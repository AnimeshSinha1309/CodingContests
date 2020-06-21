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

vpl frequency_compress(vll list) {
    vpl result;
    pll current = {list[0], 1};
    for (int i = 1; i < list.size(); i++) {
        if (list[i] == current.first)
            current.second++;
        else {
            result.push_back(current);
            current = {list[i], 1};
        }
    }
    result.push_back(current);
    return result;
}

long long mod_power(long long a, long long b) {
    long long cumulative = a, result = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            result = (result * cumulative) % MOD;
        cumulative = (cumulative * cumulative) % MOD;
    }
    return result;
}

vll factorial;
ll c(ll n, ll r) {
    if (r < 0 || r > n)
        return 0;
    return (factorial[n] *
            mod_power((factorial[r] * factorial[n - r]) % MOD, MOD - 2)) %
           MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vll a(n), b_(m);
    cin >> a >> b_;

    factorial = vll(n + 1, 1);
    for (int i = 1; i < factorial.size(); i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    // Tabulation of independent answers
    vpl b = frequency_compress(b_);
    ll prev = n;
    mll ans(m);
    for (int i = n - 1, j = b.size() - 1; i >= 0; i--) {
        while (a[i] < b[j].first) {
            j--;
            if (j < 0) {
                cout << 0 << endl;
                exit(0);
            }
        }
        if (a[i] == b[j].first)
            ans[j].push_back(prev - i), prev = i;
    }

    // Compiling together
    ll res = 1;
    for (int i = 0; i < b.size(); i++) {
        res = (c(ans[i], b[i].second) * res) % MOD;
    }
    cout << (res % MOD) << endl;
}