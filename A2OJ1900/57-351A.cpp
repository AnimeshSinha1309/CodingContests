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
    ll n;
    cin >> n;
    vld b(2 * n);
    cin >> b;
    vll a(2 * n);
    for (int i = 0; i < 2 * n; i++)
        a[i] = (ll)round(b[i] * 1000.0);
    mll dp(2 * n + 1, vll(2 * n + 1, INT64_MAX));
    dp[0][n] = 0;
    for (int i = 1; i <= 2 * n; i++) {
        // Round this number down
        for (int j = 1; j < 2 * n + 1; j++) {
            if (dp[i - 1][j] == INT64_MAX)
                continue;
            ll res = dp[i - 1][j] + (a[i - 1] % 1000);
            if (abs(res) < abs(dp[i][j - 1]))
                dp[i][j - 1] = res;
        }
        // Round this number up
        for (int j = 0; j < 2 * n; j++) {
            if (dp[i - 1][j] == INT64_MAX)
                continue;
            ll res = dp[i - 1][j] - ((1000 - a[i - 1] % 1000) % 1000);
            if (abs(res) < abs(dp[i][j + 1]))
                dp[i][j + 1] = res;
        }
    }
    cout << fixed << setprecision(3) << abs(dp[2 * n][n]) / 1000.0 << endl;
}