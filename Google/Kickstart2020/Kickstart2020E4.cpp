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
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        // Take the inputs
        ll n, m, r, s;
        cin >> n >> m >> r >> s;
        mll g(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }
        mll cost(n, vll(s, INT64_MAX));
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int stone;
                cin >> stone;
                cost[i][stone - 1] = 0;
            }
        }
        // mll recipe(r);
        // vll result(r);
        // for (int i = 0; i < r; i++) {
        // int k;
        // cin >> k;
        // for (int j = 0; j < k; j++) {
        //     int stone;
        //     cin >> stone;
        // recipe[i].push_back(stone - 1);
        // }
        // int stone;
        // cin >> stone;
        // result[i] = (stone - 1);
        // }
        // Compute answers on the graph
        // for (int i = 0; i < 2 * n; i++) {
        //     for (int j = 0; j < r; j++) {
        //         for (int u = 0; u < n; u++) {
        //             ll cur_cost = 0;
        //             for (auto el : recipe[j]) {
        //                 if (cost[u][el] == INT64_MAX) {
        //                     cur_cost = INT64_MAX;
        //                     break;
        //                 }
        //                 cur_cost += cost[u][el];
        //             }
        //             minimize(cost[u][result[j]], cur_cost);
        //         }
        //     }
        //     for (int u = 0; u < n; u++) {
        //         for (auto v : g[u]) {
        //             for (int stone = 0; stone < s; stone++) {
        //                 if (cost[u][stone] != INT64_MAX)
        //                     minimize(cost[v][stone], cost[u][stone] + 1);
        //             }
        //         }
        //     }
        // }
        // Print the answers
        // ll ans = INT64_MAX;
        // for (int i = 0; i < n; i++)
        //     minimize(ans, cost[i][0]);
        // cout << "Case #" << test << ": " << (ans >= 1e12 ? -1 : ans) << endl;
    }
}