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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        ll n, k, p;
        cin >> n >> k >> p;
        mll plates(n, vll(k));
        cin >> plates;
        vll dp(p + 1, INT64_MIN);
        dp[0] = 0;
        for (ll i = 0; i < n; i++) {
            vll next(dp);
            for (ll adding = 0, total = 0; adding <= k; adding++) {
                for (ll already = 0; already + adding <= p; already++) {
                    maximize(next[already + adding], dp[already] + total);
                }
                total += plates[i][adding];
            }
            dp = next;
        }
        cout << "Case #" << test << ": " << dp[p] << endl;
    }
}