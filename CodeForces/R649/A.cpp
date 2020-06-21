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
        ll n, x;
        cin >> n >> x;
        vll a(n);
        cin >> a;
        ll sum = accumulate(a.begin(), a.end(), 0ll);
        bool no_ans = true;
        for (int i = 0; i < n; i++) {
            if (a[i] % x != 0)
                no_ans = false;
        }
        if (no_ans) {
            cout << -1 << endl;
        } else if (sum % x == 0) {
            int i = 0;
            for (i = 0; i < n; i++) {
                if (a[i] % x != 0 || a[n - 1 - i] % x != 0)
                    break;
            }
            cout << n - 1 - i << endl;
        } else {
            cout << n << endl;
        }
    }
}