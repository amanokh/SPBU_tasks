from commons import *


def tm_method(A, B, C, G):
    n = len(A)
    s = np.zeros(n)
    t = np.zeros(n)
    y = np.zeros(n)
    s[0] = C[0] / B[0]
    t[0] = -1 * G[0] / B[0]
    for i in range(1, n):
        s[i] = C[i] / (B[i] - (A[i] * s[i - 1]))
        t[i] = ((A[i] * t[i - 1]) - G[i]) / (B[i] - (A[i] * s[i - 1]))
    y[n - 1] = t[n - 1]
    for i in range(n - 2, -1, -1):
        y[i] = s[i] * y[i + 1] + t[i]
    return y


def A_1(h_x):
    return 1 / h_x ** 2


def B_1(tau, h_x):
    return 2 / tau + 2 / h_x ** 2


def C_1(h_x):
    return 1 / h_x ** 2


def G_1(U, i, j, tau, h_y):
    return -1 * (2 * U[i][j] / tau + (U[i][j + 1] - U[i][j]) / h_y ** 2 - (U[i][j] - U[i][j - 1]) / h_y ** 2)


def A_2(h_y):
    return 1 / h_y ** 2


def B_2(tau, h_y):
    return 2 / tau + 2 / h_y ** 2


def C_2(h_y):
    return 1 / h_y ** 2


def G_2(U, i, j, tau, h_x):
    return -1 * (2 * U[i][j] / tau + (U[i + 1][j] - U[i][j]) / h_x ** 2 - (U[i][j] - U[i - 1][j]) / h_x ** 2)


def direction_method(u_init, tau):
    k = 0

    U_0 = np.copy(u_init)
    u_arr = [U_0]

    while norm(u_arr[k] - U_precise) / norm(u_arr[0] - U_precise) > eps:
        u_half = np.zeros((x_N + 1, y_N + 1))
        U_curr = np.zeros((x_N + 1, y_N + 1))

        for i in range(x_N + 1):
            u_half[i][0] = U_precise[i, 0]
            u_half[i][y_N] = U_precise[i, y_N]

        for j in range(1, y_N):
            term1 = np.zeros(x_N + 1)
            term2 = np.zeros(x_N + 1)
            term3 = np.zeros(x_N + 1)
            term4 = np.zeros(x_N + 1)

            term1[0] = 0
            term2[0] = -1
            term3[0] = 0
            term4[0] = U_precise[0, j]

            term1[x_N] = 0
            term2[x_N] = -1
            term3[x_N] = 0
            term4[x_N] = U_precise[x_N, j]
            for i in range(1, x_N):
                term1[i] = A_1(h_x)
                term2[i] = B_1(tau, h_x)
                term3[i] = C_1(h_x)
                term4[i] = G_1(u_arr[k], i, j, tau, h_y)
            lin_solve = tm_method(term1, term2, term3, term4)
            for i in range(x_N + 1):
                u_half[i][j] = lin_solve[i]

        for j in range(y_N + 1):
            U_curr[0][j] = U_precise[0, j]
            U_curr[x_N][j] = U_precise[x_N, j]

        for i in range(1, x_N):
            lterm1 = np.zeros(y_N + 1)
            lterm2 = np.zeros(y_N + 1)
            lterm3 = np.zeros(y_N + 1)
            lterm4 = np.zeros(y_N + 1)

            lterm1[0] = 0
            lterm2[0] = -1
            lterm3[0] = 0
            lterm4[0] = U_precise[i, 0]

            lterm1[y_N] = 0
            lterm2[y_N] = -1
            lterm3[y_N] = 0
            lterm4[y_N] = U_precise[i, y_N]

            for j in range(1, y_N):
                lterm1[j] = A_2(h_y)
                lterm2[j] = B_2(tau, h_y)
                lterm3[j] = C_2(h_y)
                lterm4[j] = G_2(u_half, i, j, tau, h_x)
            lin_solve_tm = tm_method(lterm1, lterm2, lterm3, lterm4)

            for j in range(y_N + 1):
                U_curr[i][j] = lin_solve_tm[j]

        u_arr.append(np.copy(U_curr))
        k += 1
    return u_arr


if __name__ == '__main__':
    print_common_info()
    print("* Метод переменных направлений *\n")

    table = pd.DataFrame(
        columns=["||F - AUk||", "rel.d.", "||Uk − u*||", "rel.error", "||Uk − Uk-1||", "r_k"])

    sigma_1 = c_1 * (4 / (h_x ** 2)) * ((np.sin((np.pi * h_x) / 2 * l_x)) ** 2)
    delta_1 = c_2 * (4 / (h_x ** 2)) * ((np.cos((np.pi * h_x) / 2 * l_x)) ** 2)

    sigma_2 = d_1 * (4 / (h_y ** 2)) * ((np.sin((np.pi * h_y) / (2 * l_y))) ** 2)
    delta_2 = d_2 * (4 / (h_y ** 2)) * ((np.cos((np.pi * h_y) / (2 * l_y))) ** 2)

    sigma_min = min(sigma_1, sigma_2)
    delta_max = max(delta_1, delta_2)

    tau_opt = 2 / np.sqrt(sigma_min * delta_max)

    dir_arr = direction_method(U_init, tau_opt)

    for k, solve in enumerate(dir_arr):
        discrepancy = dscr(solve, h_x, h_y)
        rel_error = norm(solve - U_precise) / norm(U_init - U_precise)
        abs_error = norm(solve - U_precise)
        abs_error_neighbor = norm(solve - dir_arr[k-1])

        table.loc[len(table) + 1] = [discrepancy,
                                     discrepancy / discrepancy_first,
                                     abs_error,
                                     rel_error,
                                     abs_error_neighbor,
                                     norm(solve - dir_arr[k - 1]) / norm(dir_arr[k - 1] - dir_arr[k - 2])]

    print(table)

    print('\nЧисленное решение:\n', dir_arr[-1].T)
    print('\nТочное решение:\n', U_precise.T)
