#include <bits/stdc++.h>
using namespace std;

int swaps = 0;
int compares = 0;
void bubble_sort(int *a, int size){
    int i = 0;

    while(true){
        int swaps1 = swaps;
        for (int j = 0; j < size - 1; ++j) {
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                swaps++;
            }
        }
        size--;
        compares += size;
        if (swaps == swaps1) break;
    }

    cout << "swaps: " << swaps << endl;
    cout << "comparsions: " << compares << endl<<endl;

}

int swaps_q = 0;
int compares_q = 0;

int partn(int *a, int ld, int rd){
    int p_elem = a[rd];
    int low = ld;

    for (int i = ld; i < rd; ++i) {
        if (a[i] < p_elem){
            if (i != low) {
                swap(a[i], a[low]);
                swaps_q++;
            }
            low++;
        }
        compares_q++;
    }
    if (low != rd){
        swap(a[low], a[rd]);
        swaps_q++;
    }


    return low;
}
void quicksort(int *a, int ld, int rd){
    if (ld < rd){
        int mid = partn(a, ld, rd);
        quicksort(a, ld, mid-1);
        quicksort(a, mid+1, rd);
    }
}

void csort(int *a, int size){
    swaps = 0;
    compares = 0;
    double f = 1.247;
    int step = size - 1;

    while (step >= 1){
        for (int i = 0; i + step < size; ++i){
            if (a[i] > a[i + step]){
                swap(a[i], a[i + step]);
                swaps++;
            }
            compares++;
        }
        step /= f;

    }
    bubble_sort(a, size);
}

int main(){
    int m;
    cin >> m;
    int a[m];
    int b[m];
    int d[m];

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        a[i]=c;
        b[i]=c;
        d[i]=c;
    }

    cout<<endl<<"Quick:"<<endl;

    quicksort(b, 0, m-1);
    cout<<"swaps_quick: "<<swaps_q<<endl;
    cout<<"comparsions_quick: "<< compares_q <<endl<<endl;
    for (int i = 0; i < m; i++) {
        cout << b[i] << " ";
    }

}
//
// Created by amano on 22.10.2019.
//

