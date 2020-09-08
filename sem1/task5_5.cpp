#include <bits/stdc++.h>
using namespace std;


int sm(){
    int a;
    cin>>a;
    if (a == 0) return a;
    else{
       return a + sm();
    }
}
int main(){
    cout<<sm();
}