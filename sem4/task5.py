from task1 import bisect, root_division
import math


class Root:
    def __init__(self, arg, value):
        self.arg = arg
        self.value = value
        self.d1 = -1
        self.d2 = -1


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


def f_func(x):
    return math.cos(pow(x, 2))


def p_func(x):
    return 1


def func(x):
    return p_func(x) * f_func(x)


def func_check(x, n):
    if n == 2:
        return 4 * pow(x, 3) + 6
    elif n == 4:
        return 8 * pow(x, 7) + 3 * pow(x, 3) + 2
    elif n == 6:
        return pow(x, 11) + 5 * pow(x, 8) + 1
    else:
        return 0


def int_func_check(x, n):
    if n == 2:
        return pow(x, 4) + 6 * x
    elif n == 4:
        return pow(x, 8) + 3 * pow(x, 4) / 4 + 2 * x
    elif n == 6:
        return pow(x, 12) / 12 + 5 * pow(x, 9) / 9 + x
    else:
        return 0


def legendre(x, n):
    if n == 0:
        return 1
    if n == 1:
        return x
    return (2 * n - 1) / n * legendre(x, n - 1) * x - (n - 1) / n * legendre(x, n - 2)


def show_coeffs(n_list):
    print("%-12s%-12s" % ("Узел", "Коэффициент"))
    print("%-12s%-12s" % ("--------", "--------"))

    for n in n_list:
        print("\033[1mn = %d: \033[0m" % n)

        sections = root_division(-1, 1, lambda x: legendre(x, n), n=51)
        eps = math.pow(10, -12)

        for sect in sections:
            node = bisect(sect[0], sect[1], eps, lambda x: legendre(x, n)).solution
            coeff = (2 * (1 - math.pow(node, 2))) / (math.pow(n, 2) * math.pow(legendre(node, n - 1), 2))
            print("%-12f%-12f" % (node, coeff))
        print("")


def gauss(a, b, n, func):
    sections = root_division(-1, 1, lambda x: legendre(x, n), n=51)
    nodes = []
    eps = math.pow(10, -12)

    for sect in sections:
        node = bisect(sect[0], sect[1], eps, lambda x: legendre(x, n)).solution
        coeff = (2 * (1 - math.pow(node, 2))) / (math.pow(n, 2) * math.pow(legendre(node, n - 1), 2))
        nodes.append([node, coeff])

    P = 0
    for i in range(n):
        P += nodes[i][1] * func((b - a) / 2 * nodes[i][0] + (b + a) / 2)

    return (b - a) / 2 * P


if __name__ == '__main__':
    print("КФ Гаусса, ее узлы и коэффициенты.\n"
          "Вычисление интегралов при помощи КФ Гаусса:\n")


    while True:
        print("1) Вывести узлы и коэф-ты КФ Гаусса\n"
              "2) Осуществить проверку точности\n"
              "3) Вычислить интеграл от cos(x^2)\n")
        num = int(input("\033[1mВведите номер задания (1—3): "))

        while num != -1:
            if num == 1:
                show_coeffs(list(range(1, 9)))
            elif num == 2:
                print("\nПроверка точности КФ Гаусса на многочлене наивысшей степени")
                n = int(input("\033[1mВведите N (2, 4, 6): \033[0m"))
                if n in [2, 4, 6]:
                    J_h = gauss(-1, 1, n, lambda x: func_check(x, n))
                    J = int_func_check(1, n) - int_func_check(-1, n)

                    print("\033[1mJ(h) = \033[92m %.12f\033[0m" % J_h)
                    print("\033[1m|J - J(h)| = %.12f\033[0m" % abs(J_h - J))
                else:
                    print("\033[91mНедопустимый N для проверки.\033[0m")
            elif num == 3:
                try:
                    a, b = list(map(float, input("\033[1mВведите a, b через запятую (0, pi/4): ").split(",")))
                    is_default = False
                except ValueError:
                    a = 0
                    b = math.pi / 4
                    is_default = True

                n_list = [3, 6, 7, 8]
                show_coeffs(n_list)

                for n in n_list:
                    J_h = gauss(a, b, n, func)

                    print("\033[1mn = %d: \033[0m" % n)
                    print("\033[1mJ(h) = \033[92m %.12f\033[0m" % J_h)
                    if is_default:
                        print("\033[1m|J - J(h)| = %.12f\033[0m" % abs(J_h - 0.756035774629))

            num = int(input("\n\033[1mВведите номер задания (1—3): "))






