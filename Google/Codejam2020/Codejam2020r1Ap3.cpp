#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef long double ld;
typedef vector<long double> vld;
typedef vector<vector<long double>> mld;
typedef vector<bool> vbl;
typedef vector<vector<bool>> mbl;
#define minimize(a, b) (a = min(a, b))
#define maximize(a, b) (a = max(a, b))
const long long MOD = 1e9 + 7;

template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
    ll n = vec.size();
    for (int i = 0; i < n; i++)
        in >> vec[i];
    return in;
}
template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    out << endl;
    return out;
}

bool exact(string word, const vector<string> &list) {
    for (auto target : list) {
        int i = 0, j = 0, prev_j = 0;
        for (int i = 0; i < word.size(); i++) {
            if ()
        }
    }
}

string solve() {
    string ans;
    ll n;
    cin >> n;
    vector<string> ques(n);
    cin >> ques;
    // Generate the common prefix and suffix
    vll seek_f(n, 0), seek_b(n, 0);
    for (int i = 0; i < n; i++) {
        ll len = ques[i].size();
        while (seek_f[i] < len && ques[i][seek_f[i]] != '*')
            seek_f[i]++;
        while (seek_b[i] < len && ques[i][len - 1 - seek_b[i]] != '*')
            seek_b[i]++;
        if (seek_f[i] == ques[i].size())
            return (exact(ques[i], ques) ? ques[i] : "*");
    }
    ll best_f = max_element(seek_f.begin(), seek_f.end()) - seek_f.begin();
    ll best_b = max_element(seek_b.begin(), seek_b.end()) - seek_b.begin();
    string pre = ques[best_f].substr(0, seek_f[best_f]);
    string suf = ques[best_b].substr(ques[best_b].size() - seek_b[best_b],
                                     seek_b[best_b]);
    // Check if everyone agrees to it
    bool possible = true;
    for (int i = 0; i < n && possible; i++) {
        for (int j = 0; j < seek_f[i] && possible; j++) {
            if (pre[j] != ques[i][j])
                possible = false;
        }
    }
    for (int i = 0; i < n && possible; i++) {
        ll len = ques[i].size(), suf_len = suf.size();
        for (int j = 0; j < seek_b[i] && possible; j++) {
            if (suf[suf_len - j - 1] != ques[i][len - j - 1])
                possible = false;
        }
    }
    if (!possible)
        return "*";
    // Construct the answer
    ans += pre;
    for (int i = 0; i < n; i++) {
        ll len = ques[i].size();
        for (int j = seek_f[i] + 1; j < len - 1 - seek_b[i]; j++) {
            if (ques[i][j] != '*')
                ans += ques[i][j];
        }
    }
    ans += suf;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": " << solve() << endl;
    }
}