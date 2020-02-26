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
ostream &operator<<(ostream &out, bool &val) {
    if (val)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    vll ones(n + 1, 0);
    ll ans = 0, obj = 0;
    for (int i = 1; i <= n; i++) {
        ones[i] = ones[i - 1] + a[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        // ans = all_ones - (1_i - 1_j) + (0_i - 0_j)
        // objective = 1 - 0 = 2 * 1 - (1 + 0)
        maximize(ans, ones[n] - (2 * ones[i] - i) + obj);
        maximize(obj, 2 * ones[i] - i);
    }
    cout << ans << endl;
}