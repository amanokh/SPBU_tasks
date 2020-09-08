#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int pout();
int vibor();
double *xar,c;
int n;
ifstream fin;
ofstream fout;
int main() {
    setlocale(0, "Russian");
    char strok [15];
    cout<<"Введите полное название файла - "<<endl;
    cin >> strok;
    cout<<strok<<endl;
    fin.open(strok); // доделать с переменной вводимой с клавы
    if (!fin.is_open()) {
        cerr<<"\n Не могу открыть файл ";
        return 0;
    } else {
        cout<<"\n Файл открыт "<<endl;
    }
    fin >> n;
    cout<<" n= "<<n<<endl;
    double *xar=new double[n];
    for (int i=0; i<n; i++) {
        fin >> c;
        cout<<"\nA["<< i <<"]=";
        xar[i]=c;
        cout<<xar[i]<<endl;
    }
    vibor();
    pout();
    return 0;
}
int vibor() {
    double c2,max,max1,c1;
    int n,k,z;
    cout<<"c= ";
    cin>>c2;
    c1=c2;
    max1=xar[0];
    for (int i=0; i<n; i++) {
        if (max1<xar[i]) {
            max1=xar[i];
        }
        if (c1>xar[i]) {
            z+=1;
        }
    }
    cout<<"Максимальный элемент= "<<max1<<endl;
    if (c1>max1) {
        cout <<"Элементы не найдены, введите С снова";
    } else {
        for (int i=0; i<(n-1);i++) {
            max=xar[i];
            k=i;
            for (int j=i+1;j<n;j++) {
                if ((max<xar[j]) && (xar[j]>c1)) {
                    max=xar[j];
                    k=j;
                }
            }
            xar[k]=xar[i];
            xar[i]=max;
        }
        for (int i=0; i<z; i++) {
            swap(xar[i],xar[n-i-1]);
        }
        for (int i=0; i<n; i++) {
            cout<<"\nB["<< i <<"]= "<<xar[i];
        }
    }
    return 0;
}
int pout() {
    for (int i=0; i<n; i++) {
        ofstream fout("result.txt", ios::app);
        fout<<xar[i]<<endl;
        fout.close();
    }
    delete[] xar;
    return 0;
}