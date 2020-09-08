#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, a, b = 1, c = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (a*b < 0) c++;
        b = a;
    }

    cout<<c<<endl;

}//
// Created by amano on 22.10.2019.
//

