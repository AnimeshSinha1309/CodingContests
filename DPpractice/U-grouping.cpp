#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long long, long long> pll;
#define minimize(var, val) (var = min((val), var))
#define maximize(var, val) (var = max((val), var))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Taking the input
    ll n;
    cin >> n;
    const ll subsets = 1 << n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    // Computing the Full matching value for all subsets
    ll val[subsets];
    for (int i = 0; i < subsets; i++) {
        val[i] = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if ((i & (1 << x)) && (i & (1 << y))) {
                    val[i] += a[x][y];
                }
            }
        }
    }
    for (int i = 0; i < subsets; i++)
        val[i] /= 2;
    // Computing the answer as all possible 2-partitions
    ll ans[subsets];
    memset(ans, 0, sizeof(ll) * subsets);
    for (int i = 0; i < subsets; i++) {
        ll present = __builtin_popcount(i);
        ll subsets = 1ll << present;
        int pos[present];
        for (int bit = 0, found = 0; bit < n; bit++)
            if (i & (1 << bit))
                pos[found++] = bit;
        for (int j = 0; j < subsets; j++) {
            // Preparing the j-th subset of i
            unsigned int subset = 0;
            for (int y = 0; y < present; y++) {
                if (j & 1 << y)
                    subset |= 1 << pos[y];
            }
            // Minimizing using further 2-splits
            unsigned int complement = i & ~(subset);
            maximize(ans[i], ans[complement] + ans[subset]);
        }
        // Considering the atomic expressions
        maximize(ans[i], val[i]);
    }
    cout << ans[(1 << n) - 1] << endl;
}