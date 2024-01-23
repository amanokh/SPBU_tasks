from commons import *


def theta(n):
    if n == 1:
        return [1]

    ans = []

    for i in range(n // 2):
        ans.append(theta(n // 2)[i])
        ans.append(2 * n - theta(n // 2)[i])

    return ans


def tau(k, n):
    s = np.cos(np.pi * theta(n)[k] / (2 * n))
    return 2 / (delta(h_x, h_y) + sigma(h_x, h_y) + s * (delta(h_x, h_y) - sigma(h_x, h_y)))


def triangle_chebyshev(u_init, std_output=True):
    if std_output:
        print("* Попеременно-треугольный итерационный метод с чебышевским набором параметров *\n")

    table = pd.DataFrame(
        columns=["||F - AUk||", "rel.d.", "||Uk − u*||", "rel.error", "||Uk − Uk-1||", "apost.est."])

    k = 0
    p = 4
    omega2 = 2 / np.sqrt(sigma(h_x, h_y) * delta(h_x, h_y))

    kappa1 = omega2 / h_x ** 2
    kappa2 = omega2 / h_y ** 2

    w_a = np.zeros((x_N + 1, y_N + 1))
    w_k = np.zeros((x_N + 1, y_N + 1))

    m = math.ceil(math.log(1 / eps) / r(h_x, h_y))

    U = np.copy(u_init)

    while norm(U - U_precise) / norm(U_init - U_precise) >= eps:
        U_new = np.copy(U)

        for i in range(1, x_N):
            for j in range(1, y_N):
                a = kappa1 * w_a[i - 1][j] + kappa2 * w_a[i][j - 1] + meas_k2(U, h_x, h_y)[i][j]
                b = 1 + kappa1 + kappa2
                w_a[i][j] = a / b

        for i in range(x_N - 1, 0, -1):
            for j in range(y_N - 1, 0, -1):
                a = kappa1 * w_k[i + 1][j] + kappa2 * w_k[i][j + 1] + w_a[i][j]
                b = 1 + kappa1 + kappa2
                w_k[i][j] = a / b

        for i in range(1, x_N):
            for j in range(1, y_N):
                U_new[i][j] = U[i][j] + tau(k % p, p) * w_k[i][j]

        discrepancy = dscr(U_new, h_x, h_y)
        rel_error = norm(U_new - U_precise) / norm(u_init - U_precise)
        abs_error = norm(U_new - U_precise)
        abs_error_neighbor = norm(U_new - U)

        table.loc[len(table) + 1] = [discrepancy,
                                     discrepancy / discrepancy_first,
                                     abs_error,
                                     rel_error,
                                     abs_error_neighbor,
                                     r(h_x, h_y) * abs_error_neighbor / (1 - r(h_x, h_y))]

        U = np.copy(U_new)
        k += 1

    if std_output:
        print('Теор. кол-во итераций: ', m)
        print(table)

        print('\nЧисленное решение:\n', U.T)
        print('\nТочное решение:\n', U_precise.T)

    return U, table


if __name__ == '__main__':
    print_common_info()
    triangle_chebyshev(U_init)
