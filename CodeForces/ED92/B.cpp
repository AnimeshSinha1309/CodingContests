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
    ll t;
    cin >> t;
    while (t--) {
        ll n, k, z;
        cin >> n >> k >> z;
        vll a(n);
        cin >> a;
        ll ans = INT64_MIN;
        for (int i = 0; i <= z; i++) {
            ll top = 0, sum = 0;
            for (int j = 0; j <= k - i * 2; j++) {
                sum += a[j];
                if (j > 0) {
                    maximize(top, a[j] + a[j - 1]);
                }
                if (j < n - 1) {
                    maximize(top, a[j] + a[j + 1]);
                }
            }
            maximize(ans, sum + top * i);
        }
        cout << ans << endl;
    }
}