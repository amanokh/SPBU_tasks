import math
from task2 import tabulate_value, print_table


class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

num = 0


def f_func(x):
    if num == 0:
        return 2 * math.sin(x) - pow(x, 2) / 2
    elif num == 1:
        return 1.27 * pow(x, 5) + 2.04 * x  # из вопроса
    elif num == 2:
        return 5 * x + 8  # линейная
    else:
        return 7 * pow(x, 3) - pow(x, 2) + x - 89


def p_func(x):
    return 1


def func(x):
    return p_func(x) * f_func(x)


def int_func(x):
    if num == 0:
        return -2 * math.cos(x) - pow(x, 3) / 6
    elif num == 1:
        return 1.27 / 6 * pow(x, 6) + 2.04 / 2 * pow(x, 2)
    elif num == 2:
        return 5 * pow(x, 2) / 2 + 8 * x
    else:
        return 7 * pow(x, 4) / 4 - pow(x, 3) / 3 + pow(x, 2) / 2 - 89 * x


def left_rect(func, a, b, n):
    bounds_sum = 0
    h = (b - a) / n
    for i in range(n):
        arg = a + (b - a) * i / n
        bounds_sum += func(arg)
    return bounds_sum * h


def right_rect(func, a, b, n):
    bounds_sum = 0
    h = (b - a) / n
    for i in range(n):
        arg = a + (b - a) * (i + 1) / n
        bounds_sum += func(arg)
    return bounds_sum * h


def mid_rect(func, a, b, n):
    bounds_sum = 0
    h = (b - a) / n
    for i in range(n):
        arg = a + (b - a) * (2 * i + 1) / (2 * n)
        bounds_sum += func(arg)
    return bounds_sum * h


def trapeze(func, a, b, n):
    bounds_sum = 0
    h = (b - a) / n
    for i in range(n):
        arg1 = a + (b - a) * i / n
        arg2 = a + (b - a) * (i + 1) / n

        bounds_sum += (func(arg1) + func(arg2)) / 2
    return bounds_sum * h


def simpson(func, a, b, n):
    bounds_sum = 0
    h = (b - a) / n
    for i in range(n):
        arg1 = a + (b - a) * i / n
        arg2 = a + (b - a) * (2 * i + 1) / (2 * n)
        arg3 = a + (b - a) * (i + 1) / n

        bounds_sum += func(arg1) + 4 * func(arg2) + func(arg3)
    return bounds_sum * h / 6


if __name__ == '__main__':
    print("Приближённое вычисление интеграла по \nсоставным квадратурным формулам\n\n"
          "Вид уравнения:")


    while True:
        print("0) 2 * sin(x) - x^2 / 2\n"
              "1) 1.27 * x^5 + 2.04 * x\n"
              "2) 5 * x + 8\n"
              "3) 7 * x^3 - x^2 + x - 89")

        num = int(input("\033[1mВведите номер функции: "))
        a, b = list(map(float, input("\033[1mВведите a, b через запятую: ").split(",")))
        n = int(input("\033[1mВведите число n промежутков деления: \033[0m"))

        l = int(input("\033[1mВведите параметр увеличения числа промежутков деления: \033[0m"))

        correct_ans = int_func(b) - int_func(a)
        print(f"\n\033[92mCorrect: {correct_ans:.9f}\n\033[0m")

        for method in [left_rect, right_rect, mid_rect, trapeze, simpson]:
            J_h = method(func, a, b, n)
            J_hl = method(func, a, b, n * l)

            if method.__name__ in ['left_rect', 'right_rect']:
                ast = 0
            elif method.__name__ in ['mid_rect', 'trapeze']:
                ast = 1
            else:
                ast = 3
            J_R = J_hl + (J_h - J_hl)/(1 - math.pow(l, ast + 1))

            print(
                f"\033[1m\033[93m{method.__name__}:\033[0m \n"
                f"\033[1mJ(h)\033[0m = \033[92m{J_h:.9f}\033[0m\n"
                f"\033[1mJ(h/l)\033[0m = \033[92m{J_hl:.9f}\033[0m\n"
                f"\033[1mJ*\033[0m = \033[92m{J_R:.9f}\033[0m\n"
                f"\033[1m|J - J(h)|\033[0m = {abs(J_h - correct_ans):.9f}\n"
                f"\033[1m|J - J(h/l)|\033[0m = {abs(J_hl - correct_ans):.9f}\n"
                f"\033[1m|J - J*|\033[0m = {abs(J_R - correct_ans):.9f}\n")

        i = input("Решить заново?")
