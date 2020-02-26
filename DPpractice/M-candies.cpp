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
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vll dp(k + 1), nx;
    dp[0] = 1;
    for (int person = 0; person < n; person++) {
        nx = vll(k + 2, 0);
        for (int candies = 0; candies <= k; candies++) {
            ll ways = dp[candies] % MOD;
            nx[candies] += ways;
            nx[min(candies + a[person], k) + 1] -= ways;
        }
        for (int i = 0; i <= k; i++)
            dp[i] = (nx[i] + (i > 0 ? dp[i - 1] : 0) + MOD) % MOD;
    }
    cout << (dp[k] % MOD) << endl;
}