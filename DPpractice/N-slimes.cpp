#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef vector<vector<pair<long long, long long>>> mpl;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long long, long long> pll;
#define minimize(var, val) (var = min((val), var))

const long long MOD = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mpl dp(n, vpl(n, {0, (((ll)INT32_MAX) << 16)}));
    for (int i = 0; i < n; i++) {
        dp[i][i] = {a[i], 0};
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < n && i + len - 1 < n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dp[i][j].first = dp[i][k].first + dp[k + 1][j].first;
                ll cost = dp[i][k].first + dp[i][k].second +
                          dp[k + 1][j].first + dp[k + 1][j].second;
                minimize(dp[i][j].second, cost);
            }
        }
    }
    cout << dp[0][n - 1].second << endl;
}