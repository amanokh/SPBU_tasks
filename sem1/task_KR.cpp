#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,n;
    cin>>a>>b>>n;

    cout<<((100*a+b)*n)/100<<"."<<((100*a+b)*n)%100<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(2) <<(a+b/100.0)*n<<endl;

}