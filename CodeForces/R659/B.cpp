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

ll msb(ll val) {
    for (int i = 60; i >= 0; i--) {
        if (val & (1ll << i))
            return 1 << i;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vll a(n);
        cin >> a;
        ll freq = 0;
        for (int i = 0; i < n; i++) {
            freq ^= a[i];
        }
        if (freq == 0) {
            cout << "DRAW\n";
            continue;
        }
        ll count = 0, msb_val = msb(freq);
        for (int i = 0; i < n; i++)
            if (msb_val & a[i])
                count++;

        if (n % 2 == 1) {
            // Remainder is even, no switches
            if (((count + 1) / 2) % 2 == 1)
                cout << "WIN\n";
            else
                cout << "LOSE\n";
        } else {
            // Remainder is odd, first player chooses spot
            cout << "WIN\n";
        }
    }
}