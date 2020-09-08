#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;

    int a[m][n];
    int b[m*n];

    for (int i = 0; i < m*n; ++i) {
        cin>>a[i/n][i%n];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i*n+j]=a[i][j];
            cout<<b[i*n+j]<<" ";
        }

    }
    cout<<endl;
    for (int i = 0; i < m*n; ++i) {
        a[i/n][i%n]=b[i];
        cout<<a[i/n][i%n]<<" ";
    }
    cout<<endl;
}