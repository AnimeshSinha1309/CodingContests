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
    freopen("positive.in", "r", stdin);
    freopen("positive.out", "w", stdout);
    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    vll prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = a[i] + prefix[i - 1];
    }
    ll sum = prefix[n - 1];

    vll min_post(n, 1e16), max_pre(n, -1e16);
    for (int i = 0; i < n - 1; i++) {
        max_pre[i + 1] = max(max_pre[i], prefix[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        min_post[i - 1] = min(min_post[i], prefix[i]);
    }
    // cout << prefix << min_post << max_pre;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if ((min_post[i] - (i > 0 ? prefix[i - 1] : 0)) > 0 &&
            (max_pre[i] - prefix[i] < sum) && a[i] > 0)
            ans++;
    }
    cout << ans << endl;
}