#include <bits/stdc++.h>
using namespace std;

int bs(int a[], int ld, int rd, int c){
    if (ld == rd - 1) return ld;

    int cd = (rd+ld)>>1;
    if (a[cd] > c) return bs(a, ld, cd, c);
    else return bs(a, cd, rd, c);
}

int main() {
    int n, c;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> c;

    cout<<bs(a, 0, n, c);
}