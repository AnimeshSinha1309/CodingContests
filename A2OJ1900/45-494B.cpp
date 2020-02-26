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

class KMPstring {
    string pattern;
    vll lps;

   public:
    explicit KMPstring(const string &pattern) {
        this->pattern = pattern;
        ll m = pattern.size();
        lps = vll(m + 1, 0);
        ll i = 0, j = -1;
        lps[0] = -1;
        while (i < m) {
            while (j >= 0 && pattern[i] != pattern[j])
                j = lps[j];
            i++, j++;
            lps[i] = j;
        }
    }
    vll match(const string &text) {
        vll matches;
        ll n = text.size(), m = pattern.size();
        ll i = 0, j = 0;
        while (i < n) {
            while (j >= 0 && text[i] != pattern[j])
                j = lps[j];
            i++, j++;
            if (j == m) {
                matches.push_back(i - m);
                j = lps[j];
            }
        }
        return move(matches);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Take the inputs and call the KMP functions
    string s, t;
    cin >> s >> t;
    KMPstring k(t);
    vll matches = k.match(s);
    ll n = s.size(), m = t.size();
    // Compute the last position you can start and end at i
    vll start(n + 1, -1);
    for (auto i : matches)
        start[i + m] = i + 1;
    for (int i = 1; i <= n; i++)
        maximize(start[i], start[i - 1]);
    // Run the full DP, with state as (sequences running)
    vll dp_run(n + 1, 0), dp_stp(n + 1, 0);
    dp_stp[0] = 1;
    for (int i = 1; i <= n; i++) {
        // Anything that was stopped can be arbitrarily made running
        dp_run[i] = (dp_run[i - 1] + dp_stp[i - 1]) % MOD;
        // Anything that was running and contains one occurance can be stopped
        dp_stp[i] =
            (dp_stp[i - 1] + (start[i] != -1 ? dp_run[start[i]] : 0)) % MOD;
    }
    cout << (dp_stp[n] - 1 + MOD) % MOD << endl;
}
