#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i]==a[j]) {
                for (int k = j; k < n - 1; ++k) a[k]=a[k+1];
                a[n-1]=0;
                if (a[j]!=0) j--;
            }
        }
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
}

