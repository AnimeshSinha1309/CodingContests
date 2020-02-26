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

ll check(ll sis, vll trees, ll k) {
    ll sis_remaining = k / 2;
    ll me_remaining = k / 2;
    // Give sis sized baskets to your sister
    for (auto &el : trees) {
        ll take = min(sis_remaining, el / sis);
        sis_remaining -= take;
        el -= take * sis;
    }
    if (sis_remaining > 0)
        return 0;
    // Grab remaining sis sized baskets
    ll sum = 0;
    for (auto &el : trees) {
        ll take = min(me_remaining, el / sis);
        me_remaining -= take;
        el %= sis;
        sum += take * sis;
    }
    // Now go for the smaller baskets
    sort(trees.rbegin(), trees.rend());
    for (auto &el : trees) {
        if (me_remaining == 0)
            break;
        me_remaining--;
        sum += el;
    }
    // And return the answer
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    vll trees(n);
    cin >> trees;
    ll max_berries = *max_element(trees.begin(), trees.end());
    ll ans = 0;
    for (int sis = 1; sis <= max_berries; sis++) {
        ll new_ans = check(sis, trees, k);
        maximize(ans, new_ans);
    }
    cout << ans << endl;
}