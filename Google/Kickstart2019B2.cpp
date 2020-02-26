// Tags: Dynamic-Programming, Exchange-Arguement

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

struct Stone {
    ll s, e, l;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        ll n;
        cin >> n;
        vector<Stone> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].s >> a[i].e >> a[i].l;
        sort(a.begin(), a.end(),
             [](Stone x, Stone y) { return x.s * y.l < x.l * y.s; });
        ll ans = 0, time = 0;
        for (int i = 0; i < n; i++) {
            ans += max(0ll, a[i].e - time * a[i].l);
            time += a[i].s;
        }
        cout << "Case #" << test << ": " << ans << endl;
    }
}