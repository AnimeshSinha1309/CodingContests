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

mll dp;
vll a, b;
ll n, m;
mll cost;
vll min_cost_a, min_cost_b;

void put(ll i, ll j, ll val) {
    if (i > n || j > m)
        return;
    dp[i][j] = val;
}

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
    // Taking the Inputs
    // freopen("dissim.in", "r", stdin);
    // freopen("dissim.out", "w", stdout);
    string alphabet_, a_, b_;
    cin >> alphabet_ >> a_ >> b_;
    cost = mll(alphabet_.size(), vll(alphabet_.size()));
    cin >> cost;
    n = a_.size(), m = b_.size();
    min_cost_a = vll(n, INT64_MAX);
    min_cost_b = vll(m, INT64_MAX);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            min_cost_a[i] = min(cost[i][j], min_cost_a[i]);
            min_cost_b[j] = min(cost[i][j], min_cost_b[j]);
        }
    }
    a = vll(n, 0);
    b = vll(m, 0);
    map<char, ll> alphabet;
    for (int i = 0; i < alphabet_.size(); i++)
        alphabet[alphabet_[i]] = i;
    for (int i = 0; i < n; i++)
        a[i] = alphabet[a_[i]];
    for (int i = 0; i < n; i++)
        b[i] = alphabet[b_[i]];

    // Making the DP with traceback
    dp = mll(n + 1, vll(m + 1, INT64_MAX));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            put(i + 1, j, dp[i][j] + min_cost_a[a[i]]);
            put(i, j + 1, dp[i][j] + min_cost_b[b[j]]);
            put(i + 1, j + 1, dp[i][j] + cost[a[i]][b[j]]);
        }
    }
    // Giving the Outputs
    cout << dp[n][m] << endl;
}
