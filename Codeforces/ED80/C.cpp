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
    ll n, m;
    cin >> n >> m;
    vector<mll> dp(m, mll(n, vll(n, 0)));
    for (ll len = 1; len <= n; len++) {
        for (ll i = 0; i < n && i + len - 1 < n; i++) {
            ll j = i + len - 1;
            if (len == 1)
                dp[0][i][j] = 1;
            else if (len == 2)
                dp[0][i][j] = (1 + dp[0][i + 1][j] + dp[0][i][j - 1]) % MOD;
            else
                dp[0][i][j] = ((1 + dp[0][i + 1][j] + dp[0][i][j - 1]) % MOD -
                               dp[0][i + 1][j - 1]) %
                              MOD;
        }
    }
    for (int day = 1; day < m; day++) {
        for (ll len = 1; len <= n; len++) {
            for (ll i = 0; i < n && i + len - 1 < n; i++) {
                ll j = i + len - 1;
                if (len == 1)
                    dp[day][i][j] = dp[day - 1][i][j];
                else if (len == 2)
                    dp[day][i][j] =
                        ((dp[day - 1][i][j] + dp[day][i + 1][j]) % MOD +
                         dp[day][i][j - 1]) %
                        MOD;
                else
                    dp[day][i][j] =
                        ((dp[day - 1][i][j] + dp[day][i + 1][j]) % MOD +
                         (dp[day][i][j - 1] - dp[day][i + 1][j - 1] + MOD) %
                             MOD) %
                        MOD;
            }
        }
    }
    cout << dp[m - 1][0][n - 1] % MOD << endl;
}