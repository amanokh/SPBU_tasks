#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    setlocale(0, "Russian");

    unordered_map<string, vector<pair<int, string>>> dict;
    vector<string> role_order;

    string s;
    getline(cin, s);
    getline(cin, s);
    while (s != "textLines:") {
        role_order.push_back(s);
        getline(cin, s);
    }

    int lineCounter = 0;
    while (getline(cin, s)){
        lineCounter++;
        string dict_key = s.substr(0, s.find(":"));
        s.erase(0, s.find(":") + 2);

        dict[dict_key].push_back(make_pair(lineCounter, s));
    }

    cout << dict.size() << endl;

    for (auto &role : role_order) {
        auto reversed_key = dict[role];
        cout << role << ":" << endl;
        for (auto &v_pair : reversed_key) {
            cout << v_pair.first << ") " << v_pair.second <<endl;
        }
        cout << endl;
    }
}
