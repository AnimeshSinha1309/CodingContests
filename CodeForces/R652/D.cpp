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

    ll n = 2e6 + 10;
    vll dp(n, 0);
    vbl use(n, false);
    for (int i = 2; i < n; i++) {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;
        use[i] = !use[i - 1] && !use[i - 2];
        if (use[i])
            dp[i] = (dp[i] + 4) % MOD;
    }

    ll t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        cout << dp[x - 1] << endl;
    }
}