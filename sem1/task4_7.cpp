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
int pow(int a, int b){
    int ans = 1;
    for (int i=0; i<b; i++) ans*=a;
    return ans;
}
int func(int a, int b){
    int i;
    for (i = 1; pow(i, b) < a; i++) {}
    return pow(i,b)==a ? i : -1;
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << func(a, b);
}
