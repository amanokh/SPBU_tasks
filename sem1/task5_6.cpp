#include <bits/stdc++.h>
using namespace std;

int isEasy(int a, int c){
    if (c*c<=a){
        if (a%c != 0) return isEasy(a, c+1);
        else return 0;
    } else return 1;
}
int main() {
    int a;
    cin>>a;
    cout<<isEasy(a,2);
}
