import numpy as np
import pandas as pd
import math

np.set_printoptions(precision=5)
np.set_printoptions(suppress=True)

eps = 1e-3

# концы отрезков
l_x = 1
l_y = np.pi

# кол-во разбиений
x_N = 5
y_N = 5


def u(x, y):
    return np.exp(x) * np.sin(y)


print('Манохин Антон, группа 20.Б04-мм\n'
      'Метод простой итерации, вариант 4.')
print('\neps: ', eps)

xs = np.linspace(0, l_x, x_N)
ys = np.linspace(0, l_y, y_N)
X, Y = np.meshgrid(xs, ys)

U = np.zeros((x_N, y_N))
U_precise = u(X, Y)

# Строим граничные условия
U[0, :] = U_precise[0, :]
U[-1, :] = U_precise[-1, :]
U[:, 0] = U_precise[:, 0]
U[:, -1] = U_precise[:, -1]

# Начальное приближение
U_first = np.copy(U)

h_x = l_x / (x_N - 1)
m = math.ceil(2 * math.log(1 / eps) / pow(np.pi * h_x, 2))


def r(h_x):
    sigma = 8 * pow(math.sin(math.pi * h_x / 2), 2) / pow(h_x, 2)
    delta = 8 * pow(math.cos(math.pi * h_x / 2), 2) / pow(h_x, 2)
    return (delta - sigma) / (sigma + delta)


def dscr(U, step):
    yNods = len(U) - 1
    xNods = len(U[0]) - 1
    LuResultGrid = np.zeros((yNods + 1, xNods + 1))
    for i in range(1, yNods):
        for j in range(1, xNods):
            LuResultGrid[i][j] = (U[i + 1][j] - U[i][j]) / (step ** 2) - \
                                 (U[i][j] - U[i - 1][j]) / (step ** 2) + \
                                 (U[i][j + 1] - U[i][j]) / (step ** 2) - \
                                 (U[i][j] - U[i][j - 1]) / (step ** 2)
    return np.max(np.abs(LuResultGrid[1:-1, 1:-1]))


print('Кол-во итераций: ', m)
print('Спектральный радиус: ', r(h_x))
print('')

table = pd.DataFrame(columns=["||F - AUk||", "rel.d.", "||Uk − u*||", "rel.error", "||Uk − Uk-1||", "apost.est."])
discrepancy_first = dscr(U_first, h_x)

for iter in range(m):
    U_new = np.copy(U)

    for i in range(1, x_N - 1):
        for j in range(1, y_N - 1):
            U_new[i, j] = 0.25 * (U[i - 1, j] + U[i + 1, j] + U[i, j - 1] + U[i, j + 1])

    discrepancy = dscr(U_new, h_x)
    rel_error = np.max(np.abs(U_new - U_precise)) / np.max(np.abs(U_first - U_precise))
    abs_error = np.max(np.abs(U_new - U_precise))
    abs_error_neighbor = np.max(np.abs(U_new - U))

    table.loc[len(table)] = [discrepancy,
                             discrepancy / discrepancy_first,
                             abs_error,
                             rel_error,
                             abs_error_neighbor,
                             r(h_x) * abs_error_neighbor / (1 - r(h_x))]

    U = U_new

print(table)

print('\nЧисленное решение:\n', U)
print('\nТочное решение:\n', U_precise)
