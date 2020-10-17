#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int>> b(4, vector<int>(5, 0));

    for (auto & i : b) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

}
