#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
    ifstream fin;
    double a1[3][3];
    double op[3][3];
    double b[3][3];
    int m = 3;


    string str;
    cin>>str;
    fin.open(str);


    //freopen("input_h.txt","r",stdin);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            double c;
            fin >> c;
            a1[i][j] = c;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            double c;
            fin >> c;
            op[i][j] = c;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            double s = 0;
            for (int k = 0; k < m; ++k) {
                s += a1[i][k] * op[k][j];
            }
            b[i][j] = s;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<b[i][j]<<" ";
        }
    }
}
