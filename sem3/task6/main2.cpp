#include <vector>
#include <set>
using namespace std;

vector<string> unique(vector<int> ints) {
    set<int> a;
    vector<string> res;
    for (auto & c : ints) {
        res.push_back(a.emplace(c).second ? "NO" : "YES");
    }
    return res;
}

/*int main() {
    int n;
    cin >> n;

    vector<int> a;

    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        a.push_back(c);
    }

    vector<string> res = unique(a);

    for (auto & s : res) cout << s << " ";
}*/
