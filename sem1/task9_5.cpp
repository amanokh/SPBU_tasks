#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int m;
    int swaps = 1;
    cin >> m;
    double a[m][m + 1];

    double a1[m][m + 1];
    double op[m][m + 1];
    int index[m];

    //ввод чисел
    for (int i = 0; i < m; ++i) {
        index[i] = i;
        for (int j = 0; j < m + 1; ++j) {
            double c;
            cin >> c;
            a[i][j] = c;
            a1[i][j] = c;

            if (i == j) op[i][j] = 1;
            else op[i][j] = 0;
        }
    }

    //приведение к верхнему треугольному виду
    for (int i = 0; i < m; ++i) {
        for (int ix = i; ix < m; ++ix) {
            if (a[index[ix]][i] != 0) {
                swap(index[i], index[ix]);
                if (i != ix) swaps *= -1;
                break;
            }
        }
        for (int ix = i + 1; ix < m; ++ix) {
            if (a[index[ix]][i] != 0) {
                double m_div = a[index[ix]][i] / a[index[i]][i];

                for (int j = 0; j < m + 1; ++j) {
                    a[index[ix]][j] -= m_div * a[index[i]][j];
                    op[index[ix]][j] -= m_div * op[index[i]][j];
                }
            }
        }
    }

    //приведение к диагональному виду
    for (int i = 1; i < m + 1; ++i) {
        for (int ix = i + 1; ix < m + 1; ++ix) {
            if (a[index[m - ix]][m - i] != 0) {

                double m_div = a[index[m - ix]][m - i] / a[index[m - i]][m - i];


                for (int j = 0; j < m + 1; ++j) {
                    a[index[m - ix]][m - j] -= m_div * a[index[m - i]][m - j];
                    op[index[m - ix]][m - j] -= m_div * op[index[m - i]][m - j];
                }
            }
        }
    }

    //выводим решения СЛАУ
    cout << "answers: ";
    for (int i = 0; i < m; ++i) {
        cout <<a[index[i]][m] / a[index[i]][i] << " ";
    }
    cout << endl;

    //считаем определитель
    double det = 1;
    for (int i = 0; i < m; ++i) {
        det *= a[index[i]][i];
    }
    cout << "determinant: " << det * swaps << endl;

    //находим обратную матрицу
    cout << "opposite matrix: " << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            op[index[i]][j] /= a[index[i]][i];
            cout << op[index[i]][j] << " ";
        }
        cout << endl;
    }

    cout << "check: " << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            double s = 0;
            for (int k = 0; k < m; ++k) {
                s += a1[i][k] * op[index[k]][j];
            }
            cout << s << " ";
        }
        cout<<endl;
    }


}