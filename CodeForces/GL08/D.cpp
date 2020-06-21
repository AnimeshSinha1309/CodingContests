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
    // Take the inputs
    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    sort(a.rbegin(), a.rend());
    // Do the 20 bit algo
    for (int b = 0; b < 20; b++) {
        ll count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] & (1 << b)) {
                count++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i < count) {
                a[i] |= (1 << b);
            } else {
                a[i] &= ~(1 << b);
            }
        }
    }
    // Get the sum of squares
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * a[i];
    }
    cout << ans << endl;
}