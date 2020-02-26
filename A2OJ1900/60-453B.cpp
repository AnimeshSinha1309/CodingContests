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
    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    vll primes = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                  29, 31, 37, 41, 43, 47, 53, 59};
    ll pn = primes.size();
    // DP with Bitmask
    vll dp(1 << n, 0);
    dp[0] = 1;
    for (int available = 0; available < (1 << pn); available++) {
        bitset<17> available_set(available);
        for (ll use = 0; use < n; use++) {
                }
    }
    cout << dp[(1 << n) - 1] << endl;
}