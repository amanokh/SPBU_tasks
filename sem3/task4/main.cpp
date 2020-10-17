#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string cleanSpaces(string s){
    string out = "";
    istringstream iss(s);
    vector<string> words((istream_iterator<string>(iss)),
                                     istream_iterator<string>());

    vector<string>::iterator iter = words.begin();

    for (;iter < words.end() - 1; iter++) {
        if (iter == words.end() - 2) out.append(*iter);
        else out.append(*iter + " ");
    }

    return out;
}

string except_last(string s){
    string out = "";

    istringstream iss(s);
    vector<string> words((istream_iterator<string>(iss)),
                         istream_iterator<string>());
    vector<string>::iterator iter = words.begin();

    for (auto & word : words){
        if (word != words.back()) {
            out.append(word + " ");
        }
    }
    out.resize(out.size() - 1);
    return out;
}

string reverse_word(string s){
    string out = "";

    istringstream iss(s);
    vector<string> words((istream_iterator<string>(iss)),
                         istream_iterator<string>());
    vector<string>::iterator iter = words.begin();

    for (auto & word : words){
        reverse(word.begin(), word.end());
        out.append(word + " ");
    }
    out.resize(out.size() - 1);
    return out;
}



/*int main() {
    string s;

    cin >> s;
    cout << reverse(except_last(cleanSpaces(s)));
}*/
