#include "tree.h"
#include "stack.h"
#include <iostream>
#include <regex>
#include <cstdio>

using namespace std;

int main() {
    Stack<link *> numbers{};
    Stack<char> operators{};

    char c;
    regex r("[!*+()=]");
    freopen("input.txt", "r", stdin);

    cout << "RPN: ";
    while (cin.get(c)) {
        string s(1, c);
        if (regex_match(s, r)) {             //если получаем знак (скобки, +-*/^=) - создаем поддерево, где ключ это char операции
            char lastOperation = operators.get();

            if (c == ')') {                         //прорешиваем все до скобки
                while (lastOperation != '(') {
                    operators.pop();
                    if (lastOperation == '!') {
                        link *a = numbers.pull();
                        numbers.push(connect(a, nullptr, lastOperation));
                    } else {
                        link *a = numbers.pull(), *b = numbers.pull();
                        numbers.push(connect(a, b, lastOperation));
                    }
                    cout << lastOperation << " ";
                    lastOperation = operators.get();
                }
                operators.pop();
            } else if (c == '*') {        //прорешиваем выскокоприоритетные *, !
                while (lastOperation == '*' || lastOperation == '!') {
                    operators.pop();
                    if (lastOperation == '!') {
                        link *a = numbers.pull();
                        numbers.push(connect(a, nullptr, lastOperation));
                    } else {
                        link *a = numbers.pull(), *b = numbers.pull();
                        numbers.push(connect(a, b, lastOperation));
                    }
                    cout << lastOperation << " ";
                    lastOperation = operators.get();
                }
                operators.push(c);
            } else if (c == '+') {        //прорешиваем выскокоприоритетные *, +, !
                while (lastOperation == '*' || lastOperation == '+' || lastOperation == '!') {
                    operators.pop();
                    if (lastOperation == '!') {
                        link *a = numbers.pull();
                        numbers.push(connect(a, nullptr, lastOperation));
                    } else {
                        link *a = numbers.pull(), *b = numbers.pull();
                        numbers.push(connect(a, b, lastOperation));
                    }
                    cout << lastOperation << " ";
                    lastOperation = operators.get();
                }

                operators.push(c);
            } else {                                  //получаем '(' или '!' - выше по приоритету ничего нет, добавляем
                operators.push(c);
            }
        } else {                          //получаем число - создаем лист с ключом типа 'char'
            cout << c - '0' << " ";
            link *num = new link;
            num->key = c;
            num->left = nullptr;
            num->right = nullptr;
            numbers.push(num);
        }
    }

    //прорешиваем всё оставшееся
    char lastOperation = operators.get();
    while (lastOperation) {
        operators.pop();
        if (lastOperation == '!') {
            link *a = numbers.pull();
            numbers.push(connect(a, nullptr, lastOperation));
        } else {
            link *a = numbers.pull(), *b = numbers.pull();
            numbers.push(connect(a, b, lastOperation));
        }
        cout << lastOperation << " ";
        lastOperation = operators.get();
    }

    Tree tree(numbers.get());
    cout << endl << "------tree------" << endl;
    tree.show();
    cout << "----------------" << endl;
    cout << "result: " << tree.solve() << " (" << (tree.solve() ? "true":"false") << ")" << endl;

    //tree.print();
}