#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<bool> vbl;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpl;
typedef vector<vector<long long>> mll;
typedef vector<vector<pair<long long, long long>>> mpl;
typedef vector<string> vst;
const ll MOD = 1000000007;
const ld PI = 2 * acos(0.0);
#define maximize(x, y) x = min(x, y);
#define minimize(x, y) y = max(x, y);
#define square(x) ((x) * (x))
#define cube(x) ((x) * (x) * (x))

class LazySegtree {
    int size;
    vector<long long> tree, lazy;

    void split(int node) {
        lazy[2 * node] += lazy[node];
        tree[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
        tree[2 * node + 1] += lazy[node];
        lazy[node] = 0;
    }

    void merge(int node) {
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

   public:
    LazySegtree(int n) {
        for (size = 1; size < n; size <<= 1)
            ;
        tree.assign(2 * size, 0);
        lazy.assign(2 * size, 0);
    }

    void update(int l, int r, long long delta, int node = 1, int x = 0,
                int y = -1) {
        if (y == -1)
            y = size;
        if (r <= x || l >= y)
            return;
        if (l <= x && y <= r) {
            lazy[node] += delta;
            tree[node] += delta;
        }
        split(node);
        update(l, r, delta, 2 * node, x, (x + y) / 2);
        update(l, r, delta, 2 * node + 1, (x + y) / 2, y);
        merge(node);
    }
    long long query(int l, int r, int node = 1, int x = 0, int y = -1) {
        if (y == -1)
            y = size;
        if (r <= x || l >= y)
            return 1e18;
        if (l <= x && y <= r) {
            return tree[node];
        }
        split(node);
        ll lres = query(l, r, 2 * node, x, (x + y) / 2);
        ll rres = query(l, r, 2 * node + 1, (x + y) / 2, y);
        merge(node);
        return min(lres, rres);
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    mpl start(n + 1), end(n + 1);
    for (int i = 0; i < m; i++) {
        ll l, r, x;
        cin >> l >> r >> x;
        start[l - 1].emplace_back(x, r - 1);
        end[r - 1].emplace_back(x, l - 1);
    }
    LazySegtree seg(n + 1);
    ll total_score = 0;
    for (ll i = 0, j = 0; i <= n; i++) {
        for (pll x : start[i])
            total_score += x.first;
        // DP be score + max of prefix
        ll max_el = seg.query(0, i) + total_score;
        // Add DP to position
        seg.update(i, i + 1, max_el);
        // Add negative of scores in prefix
        for (pll x : end[i]) {
            seg.update(x.second, i + 1, x.first);
            total_score -= x.first;
        }
    }
    cout << seg.query(0, n + 1) << endl;
}