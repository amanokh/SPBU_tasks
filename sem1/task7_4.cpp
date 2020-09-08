#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, a, b = 0, c = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (a >= b) {
            c = b;
            b = a;
        } else if (a >= c) c = a;
    }

    cout<<c<<endl;

}