#include "stack.h"
#include <iostream>
#include <regex>
#include <cstdio>

using namespace std;

int main() {
    Stack<int> numbers{};
    Stack<char> operators{};
    char c;
    regex r("[!*+()=]");
    freopen("input.txt", "r", stdin);

    cout << "RPN: ";
    while (cin.get(c)) {
        string s(1, c);
        if (regex_match(s, r)) {             //получаем знак (скобки, +-*/^=)
            char lastOperation = operators.get();

            if (c == ')') {                         //прорешиваем все до скобки
                while (lastOperation != '(') {
                    operators.pop();
                    if (lastOperation == '!'){
                        int a = numbers.pull();
                        numbers.push(!a);
                    } else {
                        int a = numbers.pull(), b = numbers.pull();
                        numbers.push(calculate(a, b, lastOperation));
                    }
                    cout << lastOperation << " ";
                    lastOperation = operators.get();
                }
                operators.pop();
            } else if (c == '*') {        //прорешиваем выскокоприоритетные *, !
                while (lastOperation == '*' || lastOperation == '!') {
                    operators.pop();
                    if (lastOperation == '!'){
                        int a = numbers.pull();
                        numbers.push(!a);
                    } else {
                        int a = numbers.pull(), b = numbers.pull();
                        numbers.push(calculate(a, b, lastOperation));
                    }
                    cout << lastOperation << " ";
                    lastOperation = operators.get();
                }
                operators.push(c);
            } else if (c == '+') {        //прорешиваем выскокоприоритетные *, +, !
                while (lastOperation == '*' || lastOperation == '+' || lastOperation == '!') {
                    operators.pop();
                    if (lastOperation == '!'){
                        int a = numbers.pull();
                        numbers.push(!a);
                    } else {
                        int a = numbers.pull(), b = numbers.pull();
                        numbers.push(calculate(a, b, lastOperation));
                    }
                    cout << lastOperation << " ";
                    lastOperation = operators.get();
                }

                operators.push(c);
            } else if (c == '=') {                    //прорешиваем всё
                while (lastOperation) {
                    operators.pop();
                    if (lastOperation == '!'){
                        int a = numbers.pull();
                        numbers.push(!a);
                    } else {
                        int a = numbers.pull(), b = numbers.pull();
                        numbers.push(calculate(a, b, lastOperation));
                    }
                    cout << lastOperation << " ";
                    lastOperation = operators.get();
                }
                operators.push(c);
            } else {                                  //поступает '(' или '!' - выше по приоритету ничего нет
                operators.push(c);
            }
        } else {                                    //получаем число
            cout << c - '0' << " ";
            numbers.push(c - '0');
        }
    }

    cout << endl << "result: " << numbers.get() << endl;
}