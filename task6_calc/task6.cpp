#include <iostream>
#include <regex>
#include "task6.h"

using namespace std;

int main() {
    Stack<double> numbers{};
    Stack<char> operators{};

    char c;
    char lastChar = NULL;
    string numBuff = "";
    regex r("[\\-\\/+^()*=]");
    freopen("input.txt", "r", stdin);

    cout << "RPN: ";
    while (cin.get(c)) {
        if (!lastChar && c == '-') {
            numbers.push(0);
            cout << 0 << " ";
            operators.push(c);
        } else {
            string s(1, c);
            if (c == 'e') {                     //получаем вещественную часть
                char e[5];
                e[0] = 'e';
                e[4] = '\0';
                cin.get(e[1]);
                cin.get(e[2]);
                cin.get(e[3]);
                numBuff += e;
            } else if (regex_match(s, r)) {             //получаем знак (скобки, +-*/^=)
                if (numBuff != "") {                    //сбрасываем числовой буфер
                    numbers.push(stof(numBuff));
                    cout << numBuff << " ";
                    numBuff = "";
                }
                char lastOperation = operators.get();

                if (c == ')') {                         //прорешиваем все до скобки
                    while (lastOperation != '(') {
                        operators.pop();
                        double a = numbers.pull(), b = numbers.pull();
                        numbers.push(calculate(a, b, lastOperation));
                        cout << lastOperation << " ";
                        lastOperation = operators.get();
                    }
                    operators.pop();
                } else if (c == '*' || c == '/') {        //прорешиваем выскокоприоритетные *, /, ^
                    while (lastOperation == '*' || lastOperation == '/' || lastOperation == '^') {
                        operators.pop();
                        double a = numbers.pull(), b = numbers.pull();
                        numbers.push(calculate(a, b, lastOperation));
                        cout << lastOperation << " ";
                        lastOperation = operators.get();
                    }
                    operators.push(c);
                } else if (c == '+' || c == '-') {        //прорешиваем выскокоприоритетные *, /, ^, +, -
                    if (lastChar == '(' && c == '-') {
                        numbers.push(0);
                        cout << 0 << " ";
                    } else {
                        while (lastOperation == '*' || lastOperation == '/' || lastOperation == '^' ||
                               lastOperation == '+' || lastOperation == '-') {
                            operators.pop();
                            double a = numbers.pull(), b = numbers.pull();
                            numbers.push(calculate(a, b, lastOperation));
                            cout << lastOperation << " ";
                            lastOperation = operators.get();
                        }
                    }
                    operators.push(c);
                } else if (c == '=') {                    //прорешиваем всё
                    while (lastOperation) {
                        operators.pop();
                        double a = numbers.pull(), b = numbers.pull();
                        numbers.push(calculate(a, b, lastOperation));
                        cout << lastOperation << " ";
                        lastOperation = operators.get();
                    }
                    operators.push(c);
                } else {                                  //поступает '(' или '^' - выше по приоритету ничего нет
                    operators.push(c);
                }
            } else {                                    //получаем число
                numBuff += c;
            }
            lastChar = c;
        }
    }
    cout<<endl<<"result: " << numbers.get() << endl;
}