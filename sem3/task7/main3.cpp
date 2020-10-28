#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    int a[n][m];
    set<pair<int,pair<int,pair<int,int>>>> dict; // len -- sum -- max -- num

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c;
            cin >> c;
            a[i][j] = c;
        }
    }

    for (int k = 0; k < n + m - 1; ++k) {
        int sum = 0;
        int max_num = 0;
        int len = min(k + 1, min(m + n - k -1, min(m,n)));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i + j == k) {
                    sum += a[i][j];
                    max_num = max(max_num, a[i][j]);
                }
            }
        }

        dict.insert(make_pair(len,make_pair(sum,make_pair(max_num,k+1))));
    }

    for (auto &diag : dict) {
        cout<<"line:"<<diag.second.second.second<<",len:"<<diag.first<<",sum:"<<diag.second.first<<",max:"<<diag.second.second.first<<endl;
    }
}
