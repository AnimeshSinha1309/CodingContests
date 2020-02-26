#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SearchString {
public:
    string st;
    vector<int> lps;

    explicit SearchString(string str) {
        this->st = std::move(str);
        lps = vector<int>(st.size()+1, -1);
        // length of the previous longest prefix suffix
        for (int i = 0, j = -1; i < st.size();) {
            while (j >= 0 && st[i] != st[j]) j = lps[j];
            lps[++i] = ++j;
        }
    }
};

int main() {
    string word; cin >> word; SearchString kmp(word);
    if (word.size() < 3) { cout << "Just a legend" << endl; return 0; }
    vector<int> count(word.length());
    for (int i = 1; i < kmp.lps.size() - 1; i++) count[kmp.lps[i]]++;
    for (int i = (int)count.size()-2; i >= 0; i--) count[i] += count[i+1];
    int length = kmp.lps.back(); while (count[length] < 1) length = kmp.lps[length];
    cout << (length == 0 ? "Just a legend" : word.substr(0, (unsigned)length)) << endl;
}