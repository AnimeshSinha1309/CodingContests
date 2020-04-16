#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    set<char> t(s.begin(), s.end());
    cout << (t.size() == 26 ? "YES" : "NO") << endl;
}