import commons
commons.eps = 1e-2

from commons import *

def zeidel(u_init, std_output=True):
    if std_output:
        print("* Метод Зейделя *\n")

    m = math.ceil(math.log(1 / eps) / (4 * sigma(h_x, h_y) / delta(h_x, h_y)))

    U_old = np.copy(u_init)
    U = np.copy(u_init)

    while norm(U - U_precise) / norm(U_init - U_precise) >= eps:
        U_new = np.copy(U)

        for i in range(1, x_N):
            for j in range(1, y_N):
                U_new[i, j] = (
                        (U_new[i - 1][j] / h_x ** 2 +
                         U[i + 1][j] / h_x ** 2 +
                         U_new[i][j - 1] / h_y ** 2 +
                         U[i][j + 1] / h_y ** 2) /
                        (2 / h_x ** 2 + 2 / h_y ** 2)
                )

        discrepancy = dscr(U_new, h_x, h_y)
        rel_error = norm(U_new - U_precise) / norm(u_init - U_precise)
        abs_error = norm(U_new - U_precise)
        abs_error_neighbor = norm(U_new - U)

        if norm(U - U_old) != 0:
            ro_k = norm(U_new - U) / norm(U - U_old)
        else:
            ro_k = '---'

        table.loc[len(table) + 1] = [discrepancy,
                                     discrepancy / discrepancy_first,
                                     abs_error,
                                     rel_error,
                                     abs_error_neighbor,
                                     r(h_x, h_y) * abs_error_neighbor / (1 - r(h_x, h_y)),
                                     ro_k]

        U_old = np.copy(U)
        U = np.copy(U_new)

    if std_output:
        print('Кол-во итераций: ', m)
        print(table)

        print('\nЧисленное решение:\n', U.T)
        print('\nТочное решение:\n', U_precise.T)

    return U


if __name__ == '__main__':
    print_common_info()
    zeidel(U_init)
