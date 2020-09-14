#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef vector<vpl> mpl;
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

#define assign(x, y)                                              \
    {                                                             \
        x = {x.first != -1 && a[x.first] < a[y] ? x.first : y,    \
             x.second != -1 && a[x.second] > a[y] ? x.first : y}; \
    }

void solve() {
    ll n;
    cin >> n;
    vll a(2 * n);
    cin >> a;
    vpl dp(n, {-1, -1});
    for (int pos = 2 * n - 1; pos >= 0; pos--) {
        if (a[pos] > a[pos + 1])
            continue;
        vpl next(n, {-1, -1});
        for (int j = 0; j < n; j++) {
            int next_len = n - (j + 1) - 1;
            next[next_len] = dp[j];
        }
    }
    if (dp[n - 1].first != -1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}