#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long long, long long> pll;
#define minimize(var, val) (var = min((val), var))
const long long MOD = 1e9 + 7;

int main() {
    ll n;
    string s;
    cin >> n >> s;
    mll dp(n, vll(n, 0));
    dp[0][0] = 1;
    for (int size = 1; size < n; size++) {
        char comparator = s[n - size - 1];
        if (comparator == '>') {
            ll cumulative = 0;
            for (int start = 1; start <= size; start++) {
                cumulative = (cumulative + dp[size - 1][start - 1]) % MOD;
                dp[size][start] = cumulative;
            }
        } else if (comparator == '<') {
            ll cumulative = 0;
            for (int start = size - 1; start >= 0; start--) {
                cumulative = (cumulative + dp[size - 1][start]) % MOD;
                dp[size][start] = cumulative;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans = (ans + dp[n - 1][i]) % MOD;
    cout << ans << endl;
}