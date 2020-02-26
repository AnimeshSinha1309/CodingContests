#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> mpl;
#define minimize(var, val) (var = min((val), var))
#define MOD ((long long)1e9 + 7)

ll solve(vll &digits, ll m) {
    ll size = digits.size();
    mll dp(m, vll(1 << digits.size(), 0));
    dp[0][0] = 1;
    for (int use = 1; use < (1 << size); use++) {
        bitset<18> use_set(use);
        for (int highest_digit = 0; highest_digit < size; highest_digit++) {
            if (!use_set.test(highest_digit))
                continue;
            if (use + 1 == (1 << size) && digits[highest_digit] == 0) {
                continue;
            }
            ll power = pow(10, use_set.count() - 1);
            for (ll rem = 0; rem < m; rem++) {
                dp[(rem + power * digits[highest_digit]) % m][use] +=
                    dp[rem][use & ~(1 << highest_digit)];
            }
        }
    }
    return dp[0][(1 << size) - 1];
}

int main() {
    ll n, m;
    cin >> n >> m;
    vll digits;
    for (ll copy = n; copy > 0; copy /= 10)
        digits.push_back(copy % 10);
    ll ans = solve(digits, m);
    for (int i = 0; i < 10; i++) {
        ll count = 0, factorial = 1;
        for (auto digit : digits)
            if (digit == i) {
                count++;
                factorial *= count;
            }
        ans /= factorial;
    }
    cout << ans << endl;
}
