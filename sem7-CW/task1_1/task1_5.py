import commons

commons.eps = 1e-3

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


def chebyshev(u_init, std_output=True):
    if std_output:
        print("* Итерационный метод с чебышевским набором параметров *\n")

    table = pd.DataFrame(
        columns=["||F - AUk||", "rel.d.", "||Uk − u*||", "rel.error", "||Uk − Uk-1||", "apost.est."])

    p = 4
    k = 0

    m = math.ceil(math.log(2 / eps) / (2 * math.sqrt(sigma(h_x, h_y) / delta(h_x, h_y))))

    U = np.copy(u_init)

    while norm(U - U_precise) / norm(U_init - U_precise) >= eps:
        U_new = np.copy(U)

        for i in range(1, x_N):
            for j in range(1, y_N):
                U_new[i, j] = U[i, j] + tau(k % p, p) * (
                        (U[i + 1][j] - U[i][j]) / h_x ** 2 -
                        (U[i][j] - U[i - 1][j]) / h_x ** 2 +
                        (U[i][j + 1] - U[i][j]) / h_y ** 2 -
                        (U[i][j] - U[i][j - 1]) / h_y ** 2
                ) / (2 / h_x ** 2 + 2 / h_y ** 2)

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
    chebyshev(U_init)
