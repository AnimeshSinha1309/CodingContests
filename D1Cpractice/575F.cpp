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

#define l first
#define r second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, x;
    cin >> n >> x;
    vpl a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].l >> a[i].r;
    a[0] = {x, x};
    vpl dp(n + 1, {INT64_MAX, INT64_MAX});
    dp[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        // Get the least cost of getting to here
        for (int j = 0; j < i; j++) {
            minimize(dp[i].l, dp[j].l + abs(a[j].l - a[i].l));
            minimize(dp[i].l, dp[j].r + abs(a[j].r - a[i].l));
            minimize(dp[i].r, dp[j].l + abs(a[j].l - a[i].r));
            minimize(dp[i].r, dp[j].r + abs(a[j].r - a[i].r));
        }
        // Update the penalities for not taking refuge here
        for (int j = 0; j < i; j++) {
            if (a[j].l > a[i].r || a[j].l < a[i].l)
                dp[j].l += min(abs(a[i].l - a[j].l), abs(a[i].r - a[j].l));
            if (a[j].r > a[i].r || a[j].r < a[i].l)
                dp[j].r += min(abs(a[i].l - a[j].r), abs(a[i].r - a[j].r));
        }
    }
    ll ans = INT64_MAX;
    for (int i = 0; i <= n; i++) {
        minimize(ans, dp[i].l);
        minimize(ans, dp[i].r);
    }
    cout << ans << endl;
}