#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, a, c = 0, s = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (a % 2) s = max(++c, s);
        else{
            c = 0;
        }
    }



    cout<<s<<endl;

}
// Created by amano on 22.10.2019.
//

