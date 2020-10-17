#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;


    vector<vector<int>> a(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = abs(i - j) + 1;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<vector<int>> b(m + 1, vector<int>(n + 1, 0));

    for (int step = 0; step < min(m, n); ++step) {
        if (step % 2 == 0) {
            int first = step / 2 + 1;
            for (int i = 0; i < n - step; ++i) b[first][first + i] = b[first][first + i - 1] + 1; //по строчке вправо
            for (int j = 0; j < m - step - 1; ++j)
                b[first + j + 1][n - step / 2] = b[first + j][n - step / 2] + 1; //по столбцу вниз
        } else {
            int iStart = m - step / 2;
            int jStart = n - step / 2 - 1;
            for (int i = 0; i < n - step; ++i) b[iStart][jStart - i] = b[iStart][jStart - i + 1] + 1; //по строчке влево
            for (int j = 0; j < m - step - 1; ++j)
                b[iStart - j - 1][step / 2 + 1] = b[iStart - j][step / 2 + 1] + 1; //по столбцу вверх
        }
    }

    for (int k = 0; k < m; ++k) {
        for (int i = 0; i < n; ++i) {
            cout << b[k + 1][i + 1] << " ";
        }
        cout << endl;
    }
}