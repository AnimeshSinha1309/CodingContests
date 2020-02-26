#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> mbl;
#define minimize(var, val) (var = min((val), var))
#define MOD ((long long)1e9 + 7)

int main() {
    ll n;
    cin >> n;
    vector<vector<bool>> a(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            a[i][j] = temp == 1;
        }
    }
    vll dp(1 << n, 0);
    dp[0] = 1;
    for (int women = 0; women < (1 << n); women++) {
        bitset<21> women_set(women);
        ll man = women_set.count() - 1;
        for (int woman_marrying = 0; woman_marrying < n; woman_marrying++) {
            if (!women_set.test(woman_marrying) || !a[man][woman_marrying])
                continue;
            dp[women] = (dp[women] + dp[women & ~(1 << woman_marrying)]) % MOD;
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}