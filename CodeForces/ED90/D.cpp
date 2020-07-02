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
        // Take inputs
        ll n;
        cin >> n;
        vll a(n);
        cin >> a;
        // Get globals
        ll sum = 0;
        for (int i = 0; i < n; i += 2) {
            sum += a[i];
        }
        ll pre, bot, res = 0;
        // First pass
        pre = 0, bot = 0;
        for (int i = 1; i < n; i += 2) {
            pre += (a[i] - a[i - 1]);
            res = max(pre - bot, res);
            bot = min(pre, bot);
        }
        // Second pass
        pre = 0, bot = 0;
        for (int i = 2; i < n; i += 2) {
            pre += (a[i - 1] - a[i]);
            res = max(pre - bot, res);
            bot = min(pre, bot);
        }
        // Output
        cout << sum + res << endl;
    }
}