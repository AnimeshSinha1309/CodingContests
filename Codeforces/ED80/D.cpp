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
    ll n, m;
    cin >> n >> m;
    mll in(n, vll(m));
    cin >> in;
    vll max_minima(1ll << m, 0);
    vll credits(1ll << m, 0);
    // Compute minima with all active sets
    for (int set = 0; set < (1ll << m); set++) {
        for (int i = 0; i < n; i++) {
            ll cur_minima = INT32_MAX;
            for (int bit = 0; bit < m; bit++) {
                if (set & (1 << bit))
                    cur_minima = min(cur_minima, in[i][bit]);
            }
            if (max_minima[set] < cur_minima) {
                max_minima[set] = cur_minima;
                credits[set] = i;
            }
        }
    }
    // Perform DP Bitmask
    ll ans = -1;
    ll all = (1ll << m) - 1;
    pll ans_pair = {0, 0};
    for (int mask = 0; mask < (1ll << m); ++mask) {
        ll temp_ans = min(max_minima[mask], max_minima[all & ~mask]);
        if (temp_ans > ans) {
            ans = temp_ans;
            ans_pair = {credits[mask], credits[all & ~mask]};
        }
    }
    cout << ans_pair.first + 1 << " " << ans_pair.second + 1 << endl;
}