// Problem on DP - Coin Change

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

    const ll MAX_N = 3, MAX_K = 3;
    // Computing factorials for combinatorial use
    vll fact(10000, 1);
    for (int i = 2; i < fact.size(); i++) {
        fact[i] = fact[i - 1] * i;
    }
    // Computing ways to get each possible sum with unique values
    mll dp_unq(MAX_N + 1, vll(MAX_K + 1, 0));  // dp[required_sum][slots] = ways
    for (int slots = 0; slots <= MAX_K; slots++)
        dp_unq[0][slots] = 1;
    for (ll slots = 1; slots <= MAX_K; slots++) {
        for (ll i = 1; i <= MAX_N; i++) {
            dp_unq[i][slots] = dp_unq[i][slots - 1] + dp_unq[i - 1][slots];
        }
    }
    // Computing ways to get each possible sum with any values
    mll dp_sim(MAX_N + 1, vll(MAX_K + 1, 0));
    dp_sim[0][0] = 1;
    for (ll i = 1; i <= MAX_N; i++) {
        for (ll j = 1; j <= MAX_K; j++) {
            dp_sim[i][j] = fact[i + j - 1] / (fact[i] * fact[j - 1]);
        }
    }
    // Answering each test
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        n -= k;
        ll ans = 0;
        for (int i = 0; i <= n; i++)
            ans += dp_sim[i][k] * dp_unq[n - i][k];
        cout << ans << endl;
    }
}