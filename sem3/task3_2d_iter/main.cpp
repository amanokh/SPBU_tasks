#include <vector>
#include <iostream>

using namespace std;

vector<int> convert(vector<vector<int>> a){
    vector<int> b(a.size() * a.begin()->size());

    vector<int>::iterator col;
    vector<vector<int>>::iterator row;

    for (row = a.begin(); row < a.end(); ++row) {
        for (col = (*row).begin(); col < (*row).end(); ++col){
            auto i = b.begin() + (row - a.begin()) * a.begin()->size() + (col - row->begin());
            *i = *col;
        }
    }
    return b;
}

vector<vector<int>> convert(vector<int> a, int m, int n){
    vector<vector<int>> b(m, vector<int>(n, 0));
    vector<int>::iterator iter;

    for (iter = a.begin(); iter < a.end(); ++iter){
        auto row = b.begin() + (iter - a.begin()) / n;
        auto col = row->begin() + (iter - a.begin()) % n;
        *col = *iter;
    }
    return b;
}

int sum(int a, int b){
    return a+b;
}

/*int main() {
    vector<int> a = {1,3,5,6,7,8,8,9,9,76,89,90};

    vector<vector<int>> b = convert(a, 4, 3);
    for (auto & i : b) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;

    vector<int> c = convert(b);

    for (auto & i : c){
        cout<< i << " ";
    }
}*/
