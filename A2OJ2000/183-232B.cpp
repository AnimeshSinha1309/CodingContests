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

long long mod_power(long long a, long long b, long long MOD) {
    long long cumulative = a, result = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            result = (result * cumulative) % MOD;
        cumulative = (cumulative * cumulative) % MOD;
    }
    return result;
}

long long mod_multiply(long long a, long long b, long long MOD) {
    long long cumulative = a, result = 0;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            result = (result + cumulative) % MOD;
        cumulative = (cumulative + cumulative) % MOD;
    }
    return result;
}

long long mod_inverse(long long a, long long MOD) {
    return mod_power(a, MOD - 2, MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Take the inputs
    ll n, m, k;
    cin >> n >> m >> k;
    // Cache useful formulae
    vll multiplicity(n);
    for (int i = 0; i < n; i++)
        multiplicity[i] = (1 + (m - i - 1) / n) % MOD;
    mll comb(n + 1, vll(n + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                comb[i][j] = 1;
            else
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }
    mll cache(n, vll(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cache[i][j] = mod_power(comb[n][j], multiplicity[i], MOD);
        }
    }
    // Compute the DP
    vll dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vll next(k + 1);
        for (int has = 0; has <= k; has++) {
            for (int had = max(has - n, 0ll); had <= has; had++) {
                next[has] = (next[has] + dp[had] * cache[i][has - had]) % MOD;
            }
        }
        dp = next;
    }
    cout << dp[k] << endl;
}