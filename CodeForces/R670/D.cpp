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
    vll delta(n - 1);
    ll net_delta = 0;
    for (int i = 0; i < n - 1; i++) {
        delta[i] = a[i + 1] - a[i];
        if (delta[i] > 0)
            net_delta += delta[i];
    }
    cout << ((a[0] + net_delta) > 0 ? (a[0] + net_delta + 1) / 2
                                    : (a[0] + net_delta) / 2)
         << endl;

    int q;
    cin >> q;
    while (q--) {
        ll l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        if (l == 0)
            a[0] += x;
        if (l > 0) {
            net_delta -= max(delta[l - 1], 0ll);
            delta[l - 1] += x;
            net_delta += max(delta[l - 1], 0ll);
        }
        if (r < n - 1) {
            net_delta -= max(delta[r], 0ll);
            delta[r] -= x;
            net_delta += max(delta[r], 0ll);
        }

        cout << ((a[0] + net_delta) > 0 ? (a[0] + net_delta + 1) / 2
                                        : (a[0] + net_delta) / 2)
             << endl;
    }
}