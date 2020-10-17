#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

vector<pair<int, int>> dots_sort(vector<pair<int, int>> a) {
    vector<pair<float, pair<int, int>>> b;
    for (auto & i : a) {
        b.push_back(make_pair(sqrt((i.first)*(i.first) + (i.second)*(i.second)), i));
    }
    sort(b.begin(), b.end());
    vector<pair<int, int>> res;
    for (auto & i : b) {
        res.push_back(i.second);
    }
    return res;
}

/*int main() {
    int n;
    cin >> n;

    vector<pair<float, pair<int, int>>> a;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(sqrt(x * x + y * y), make_pair(x, y));
    }

    vector<pair<float, pair<int, int>>> b = dots_sort(a);

    for (auto &i : b){
        cout<< i.second.first << " " << i.second.second << endl;
    }
}*/

