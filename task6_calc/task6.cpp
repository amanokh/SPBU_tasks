#include <bits/stdc++.h>
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
            if (c == 'e') {                     //�������� ������������ �����
                char e[5];
                e[0] = 'e';
                e[4] = '\0';
                cin.get(e[1]);
                cin.get(e[2]);
                cin.get(e[3]);
                numBuff += e;
            } else if (regex_match(s, r)) {             //�������� ���� (������, +-*/^=)
                if (numBuff != "") {                    //���������� �������� �����
                    numbers.push(stof(numBuff));
                    cout << numBuff << " ";
                    numBuff = "";
                }
                char lastOperation = operators.get();

                if (c == ')') {                         //����������� ��� �� ������
                    while (lastOperation != '(') {
                        operators.pop();
                        double a = numbers.pull(), b = numbers.pull();
                        numbers.push(calculate(a, b, lastOperation));
                        cout << lastOperation << " ";
                        lastOperation = operators.get();
                    }
                    operators.pop();
                } else if (c == '*' || c == '/') {        //����������� ������������������� *, /, ^
                    while (lastOperation == '*' || lastOperation == '/' || lastOperation == '^') {
                        operators.pop();
                        double a = numbers.pull(), b = numbers.pull();
                        numbers.push(calculate(a, b, lastOperation));
                        cout << lastOperation << " ";
                        lastOperation = operators.get();
                    }
                    operators.push(c);
                } else if (c == '+' || c == '-') {        //����������� ������������������� *, /, ^, +, -
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
                } else if (c == '=') {                    //����������� ��
                    while (lastOperation) {
                        operators.pop();
                        double a = numbers.pull(), b = numbers.pull();
                        numbers.push(calculate(a, b, lastOperation));
                        cout << lastOperation << " ";
                        lastOperation = operators.get();
                    }
                    operators.push(c);
                } else {                                  //��������� '(' ��� '^' - ���� �� ���������� ������ ���
                    operators.push(c);
                }
            } else {                                    //�������� �����
                numBuff += c;
            }
            lastChar = c;
        }
    }
    cout<<endl<<"result: " << numbers.get() << endl;
}