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
void cancel(int a, int b, int *p, int *q){
    int c = gcd(a,b);
    a /= c;
    b /= c;
    *p = a;
    *q = b;
}
int main(){
    int a, b, c, d;
    int p, q;
    cin >> a >> b >> c >> d;
    cancel(a, b, &p, &q);
    a = p;
    b = q;
    cancel(c, d, &p, &q);
    cancel(a *(lcm(b,q) / b) + p * (lcm(b,q) / q) , lcm(b,q), &p, &q);
    cout << p <<"/"<<q<<endl;
}

//
// Created by amano on 17.09.2019.
//

