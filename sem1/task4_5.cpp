//
// Created by amano on 17.09.2019.
//

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    while (a != 0 && b != 0) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}
int lcm(int a, int b){
    return a * b / gcd(a, b);
}
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << lcm(a,lcm(b,c)) << endl;
}
