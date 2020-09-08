#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    int a[m], b[n], c[m+n];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ind = 0;
    for (int i = 0; i < m; ++i) {
        if (a[i] <= b[ind]) c[ind + i]=a[i];
        else{
            while (ind < n && b[ind] < a[i]){
                c[ind + i] = b[ind];
                ind++;
            }
            c[ind + i]=a[i];
        }
    }
    for (int i = ind; i < n; ++i) c[i+m] = b[i];

    for (int j = 0; j < m + n; ++j) {
        cout<<c[j]<<" ";
    }
}