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

struct Query {
    int digit;
    string replace;
    ll result = 0;
};

long long mod_power(long long a, long long b, long long MOD) {
    long long cumulative = a, result = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            result = (result * cumulative) % MOD;
        cumulative = (cumulative * cumulative) % MOD;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string st;
    cin >> st;
    ll n;
    cin >> n;
    vector<Query> q(n);
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        q[i].digit = temp[0] - '0';
        q[i].replace = temp.substr(3);
    }
    vll remainders = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vll shifts(10, 1);
    for (int i = n - 1; i >= 0; i--) {
        ll k = 0;
        for (int j = q[i].replace.size() - 1; j >= 0; j--) {
            int digit = q[i].replace[j] - '0';
            q[i].result = (q[i].result +
                           (remainders[digit] * mod_power(10, k, MOD)) % MOD) %
                          MOD;
            k = (k + shifts[digit]) % (MOD - 1);
        }
        remainders[q[i].digit] = q[i].result % MOD;
        shifts[q[i].digit] = k;
    }
    ll ans = 0;
    for (int j = st.size() - 1, k = 0; j >= 0; j--) {
        int digit = st[j] - '0';
        ans = (ans + remainders[digit] * mod_power(10, k, MOD)) % MOD;
        k = (k + shifts[digit]) % (MOD - 1);
    }
    cout << ans << endl;
}