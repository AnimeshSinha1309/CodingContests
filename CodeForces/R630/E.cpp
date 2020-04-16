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
const long long MOD = 998244353;

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

long long mod_power(long long a, long long b, long long MOD) {
    long long cumulative = a, result = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            result = (result * cumulative) % MOD;
        cumulative = (cumulative * cumulative) % MOD;
    }
    return result;
}

long long mod_multiply(long long a, long long b, long long MOD) {
    long long cumulative = a, result = 0;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            result = (result + cumulative) % MOD;
        cumulative = (cumulative + cumulative) % MOD;
    }
    return result;
}

long long mod_inverse(long long a, long long MOD) {
    return mod_power(a, MOD - 2, MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    ll tmp = mod_power(r - l + 1, (n * m), MOD);
    if ((n * m) % 2 == 0) {
        if ((r - l + 1) % 2 == 0) {
            // If range is even, then just half the result
            cout << (tmp * mod_inverse(2, MOD)) % MOD << endl;
        } else if (l % 2 == 0) {
            // If the range has extra even term, add 1 and half
            cout << (((tmp + 1) % MOD) * mod_inverse(2, MOD)) % MOD << endl;
        } else if (l % 2 == 1) {
            // If the range has extra odd term, add 1 and half
            cout << (((tmp + 1) % MOD) * mod_inverse(2, MOD)) % MOD << endl;
        }
    } else {
        // If odd grid then go do anything
        cout << tmp << endl;
    }
}