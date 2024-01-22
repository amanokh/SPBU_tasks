import numpy as np
import pandas as pd
import math

np.set_printoptions(precision=5)
np.set_printoptions(suppress=True)
pd.set_option('display.max_columns', 10)

eps = 1e-3

c_1 = c_2 = 1
d_1 = d_2 = 1

# концы отрезков
l_x = 1
l_y = np.pi

# кол-во разбиений
x_N = 5
y_N = 5

xs = np.linspace(0, l_x, x_N + 1)
ys = np.linspace(0, l_y, y_N + 1)
X, Y = np.meshgrid(xs, ys)


def u(x, y):
    return np.exp(x) * np.sin(y)


U_init = np.zeros((x_N + 1, y_N + 1))
U_precise = u(X, Y).transpose()

# Строим граничные условия (начального прилижения)
U_init[0, :] = U_precise[0, :]
U_init[-1, :] = U_precise[-1, :]
U_init[:, 0] = U_precise[:, 0]
U_init[:, -1] = U_precise[:, -1]


h_x = l_x / x_N
h_y = l_y / y_N


def sigma(h_x, h_y):
    return c_1 * 4 / (h_x ** 2) * math.sin(math.pi * h_x / (2 * l_x)) ** 2 + d_1 * 4 / (h_y ** 2) * math.sin(
        math.pi * h_y / (2 * l_y)) ** 2


def delta(h_x, h_y):
    return c_2 * 4 / (h_x ** 2) * math.cos(math.pi * h_x / (2 * l_x)) ** 2 + d_2 * 4 / (h_y ** 2) * math.cos(
        math.pi * h_y / (2 * l_y)) ** 2


def r(h_x, h_y):
    return (delta(h_x, h_y) - sigma(h_x, h_y)) / (delta(h_x, h_y) + sigma(h_x, h_y))


def norm(U):
    return np.max(np.abs(U[1:-1, 1:-1]))


def dscr(U, h_x, h_y):
    x_nods = len(U)
    y_nods = len(U[0])
    LuResultGrid = np.zeros((x_nods, y_nods))
    for i in range(1, x_nods - 1):
        for j in range(1, y_nods - 1):
            LuResultGrid[i][j] = (U[i + 1][j] - U[i][j]) / (h_x ** 2) - \
                                 (U[i][j] - U[i - 1][j]) / (h_x ** 2) + \
                                 (U[i][j + 1] - U[i][j]) / (h_y ** 2) - \
                                 (U[i][j] - U[i][j - 1]) / (h_y ** 2)
    return norm(LuResultGrid)


table = pd.DataFrame(
    columns=["||F - AUk||", "rel.d.", "||Uk − u*||", "rel.error", "||Uk − Uk-1||", "apost.est.", "ro_k"])
discrepancy_first = dscr(U_init, h_x, h_y)
measure_approximation = dscr(U_precise, h_x, h_y)


def print_common_info():
    print('Манохин Антон, группа 20.Б04-мм. Вариант 4.')
    print('eps: ', eps)
    print('N: ', x_N)
    print('M: ', y_N)

    print('Спектральный радиус: ', r(h_x, h_y))
    print('Спектральный радиус ** 2: ', r(h_x, h_y) ** 2)
    print('')
    print('sigma:', sigma(h_x, h_y))
    print('delta:', delta(h_x, h_y))

    print('\nМера аппроксимации ||F − AU^*||:', measure_approximation)
    print('Норма невязки нулевого приближения ||F − AU^0||:', discrepancy_first)
    print('')
