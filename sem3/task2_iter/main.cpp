#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int n, q = 0;
    cin >> n;
    vector<int> a;
    vector<int>::iterator iter;

    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        a.push_back(c);
    }

    for (iter = ++a.begin(); iter < a.end(); ++iter){
        if (*iter * *prev(iter) < 0) q++;
    }

    cout << q;

    return 0;
}
