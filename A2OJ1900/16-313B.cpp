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
    string st;
    cin >> st;
    ll n = st.size();
    st = 'X' + st;
    vll count(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        count[i] = count[i - 1] + (st[i] == st[i - 1] ? 1 : 0);
    }
    ll q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll ans = count[r] - count[l - 1];
        if (st[l - 1] == st[l])
            ans--;
        cout << ans << endl;
    }
}