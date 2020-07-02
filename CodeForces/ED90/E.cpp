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
    for (ll i = 0; i < n; i++)
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
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        for (ll i = 0; i <= k; i++) {
            n -= i;
        }
        ll res = INT64_MAX;
        for (ll mu = 1; mu < 17; mu++) {
            for (ll kappa = 0; kappa < k + 1; kappa++) {
                ll nx = n + 9 * mu * kappa;
                if (nx % (k + 1) == 0 && nx >= 0) {
                    nx /= (k + 1);
                    // Prepare First digit and the 9s
                    ll ans = 0,
                       shift = (kappa == 0 ? min(nx, 9 - k) : (9 - k + kappa));
                    nx -= (shift + (mu - 1) * 9);
                    if (nx < 0)
                        continue;
                    // Put in the other digits
                    ans = nx % 9;
                    nx -= nx % 9;
                    if (nx > 0)
                        continue;
                    // put in the 9s
                    for (ll _ = 0; _ < mu - 1; _++)
                        ans = ans * 10 + 9;
                    ans = ans * 10 + shift;
                    // output minimize
                    res = min(res, ans);
                }
            }
        }
        cout << (res == INT64_MAX ? -1 : res) << endl;
    }
}