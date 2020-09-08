#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int pout(int n);
int vibor(int n);

double *xar, c;

int main() {
    setlocale(0, "Russian");
    char strok [15];
    cout<<"Введите полное название файла - "<<endl;
    cin >> strok;
    cout<<strok<<endl;

    ifstream fin;
    fin.open(strok); // доделать с переменной вводимой с клавы
    if (!fin.is_open()) {
        cerr << "\n Не могу открыть файл ";
        return 0;
    } else {
        cout << "\n Файл открыт " << endl;
    }

    int n;
    fin >> n;
    cout << " n= " << n << endl;
    xar = new double[n];
    for (int i = 0; i < n; i++) {
        fin >> c;
        cout << "A[" << i << "]=";
        xar[i] = c;
        cout << xar[i] << endl;
    }
    vibor(n);
    pout(n);
    fin.close();
    return 0;
}

int vibor(int n) {
    double c2, max, max1, c1;
    int z = 0;
    cout << "c= ";
    cin >> c2;
    c1 = c2;
    max1 = xar[0];
    for (int i = 0; i < n; i++) {
        if (max1 < xar[i]) {
            max1 = xar[i];
        }
        if (c1 > xar[i]) {
            z += 1;
        }
    }
    cout << "Максимальный элемент= " << max1 << endl;

    if (c1 > max1) {
        cout << "Элементы не найдены, введите С снова";
    } else {
        for (int i = 0; i < (n - 1); i++) {
            max = xar[i];
            int k = i;
            for (int j = i + 1; j < n; j++) {
                if ((max < xar[j]) && (c1 < xar[j])) {
                    max = xar[j];
                    k = j;
                }
            }
            swap(xar[i], xar[k]);
        }
        for (int i = 0; i < n/2; i++) {
            swap(xar[i], xar[n - i - 1]);
        }
        for (int i = 0; i < n; i++) {
            cout << "\nB[" << i << "]= " << xar[i];
        }
    }
    return 0;
}

int pout(int n) {
    ofstream fout("result.txt");
    for (int i = 0; i < n; i++) {
        fout << xar[i] << endl;
    }
    fout.close();

    delete[] xar;
    return 0;
}
