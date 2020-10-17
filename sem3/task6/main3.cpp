#include <map>
#include <string>

using namespace std;

string dictionary(map<string, string> a, string word) {
    string ans;
    string wordFound = a[word];
    if (wordFound.empty()) {
        for (auto elem : a) {
            if (elem.second == word) ans = elem.first;
        }
    } else ans = wordFound;
    return ans;
}

/*int main() {
    int n;
    cin >> n;

    map<string, string> a;

    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        a.emplace(s1, s2);
    }

    string word, wordFound;
    cin >> word;

    wordFound = a[word];
    if (wordFound.empty()){
        for (auto elem : a){
            if (elem.second == word) cout << elem.first;
        }
    } else cout << wordFound;
}*/

