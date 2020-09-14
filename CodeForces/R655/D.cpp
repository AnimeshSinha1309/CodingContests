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
    vll a(n);
    cin >> a;
    vll odd_pre(n, 0), even_pre(n, 0), odd_suf(n, 0), even_suf(n, 0);
    odd_pre[0] = 0;
    for (int i = 1; i < n; i++) {
        odd_pre[i] = (i % 2 == 1 ? a[i] : 0) + odd_pre[i - 1];
    }
    even_pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        even_pre[i] = (i % 2 == 0 ? a[i] : 0) + even_pre[i - 1];
    }
    odd_suf[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        odd_suf[i] = (i % 2 == 1 ? a[i] : 0) + odd_suf[i + 1];
    }
    even_suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        even_suf[i] = (i % 2 == 0 ? a[i] : 0) + even_suf[i + 1];
    }

    // cout << odd_pre << odd_suf << even_pre << even_suf;
    ll ans = even_pre[n - 1];
    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0)
            maximize(ans, even_pre[i] + odd_suf[i + 1]);
        else
            maximize(ans, odd_pre[i] + even_suf[i + 1]);
    }
    cout << ans << endl;
}