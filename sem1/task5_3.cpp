#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}
int maxDig(int n){
    return n < 10 ? n : (max(n % 10, maxDig(n / 10)));
}
int revPrint(int n){
    if (n > 0) {
        cout << n % 10;
        revPrint(n / 10);
    }
}
int main(){
    int a;
    cin>>a;
    cout<<maxDig(a)<<endl;
    revPrint(a);

}