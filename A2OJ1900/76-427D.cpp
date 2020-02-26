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
    string w1, w2; cin >> w1 >> w2; string word = w1 + "$" + w2;
    int length = INT32_MAX; int size = (int)max(w1.size(), w2.size()) + 1;
    for (unsigned int i = 1; i <= w1.size(); i++) {
        SearchString kmp(word.substr(i));
        vector<int> freq1(size, 0), freq2(size, 0);
        for (int pos = i; pos <= w1.size(); pos++) freq1[kmp.lps[pos]]++;
        for (int pos = (int)w1.size()+1; pos <= word.size(); pos++) freq2[kmp.lps[pos]]++;
        for (int choice = 0; choice < size; choice++) {
            if (freq1[choice] <= 1 && freq2[choice] == 1) { length = min(length, choice); break; }
        }
    } cout << length << endl;
}