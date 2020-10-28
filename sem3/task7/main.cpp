#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    setlocale(0, "Russian");
    int n;
    cin >> n;
    cin.ignore();

    map<string, set<string>> dict;

    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);

        string dict_key = s.substr(0, s.find(" - "));
        s.erase(0, s.find(" - ") + 3);

        while (!s.empty()){
            if (s.find(",") != string::npos) {
                string value = s.substr(0, s.find(","));
                s.erase(0, s.find(",") + 1);

                dict[value].insert(dict_key);
            } else {
                string value = s;
                s.erase();
                dict[value].insert(dict_key);
            }
        }
    }

    cout << dict.size() << endl;
    for (auto &reversed_key : dict) {
        cout << reversed_key.first << " - ";
        for (auto it = reversed_key.second.begin(); it != reversed_key.second.end(); ++it) {
            if (it == reversed_key.second.begin()) cout << *it;
            else cout << ", " << *it;
        }
        cout << endl;
    }
}
