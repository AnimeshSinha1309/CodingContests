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
    string k;
    cin >> k;
    ll d;
    cin >> d;
    mll dp(k.size() + 1, vll(d, 0));
    ll cumulative = 0;
    for (int i = 1; i <= k.size(); i++) {
        for (int digit = 0; digit < 10; digit++) {
            for (int sum = 0; sum < d; sum++) {
                dp[i][(sum + digit) % d] =
                    (dp[i][(sum + digit) % d] + dp[i - 1][sum]) % MOD;
            }
        }
        for (int digit = 0; digit < k[i - 1] - '0'; digit++) {
            dp[i][(cumulative + digit) % d] =
                (dp[i][(cumulative + digit) % d] + 1) % MOD;
        }
        cumulative = (cumulative + k[i - 1] - '0') % d;
    }
    dp[k.size()][cumulative] = (dp[k.size()][cumulative] + 1) % MOD;
    cout << (dp[k.size()][0] - 1 + MOD) % MOD << endl;
}