//
// Created by amano on 10.09.2019.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sq;
    cin >> n;
    sq = sqrt(n);

    for (int i = 2; i < sq; ++i) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n != 1) cout << n;

}
