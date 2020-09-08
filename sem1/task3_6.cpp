//
// Created by amano on 10.09.2019.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, sum = 0;
    cin >> n;

    a = 1 + n * (n - 1);
    for (int i = 0; i < n; ++i) {
        cout << a << " ";
        sum+=a;
        a+=2;
    }
    cout<<"= "<<sum;
}
