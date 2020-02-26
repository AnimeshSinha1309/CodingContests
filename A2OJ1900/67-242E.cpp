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

class LazySegtree {
    int size;
    vector<int> tree;
    vector<int> range;
    vector<bool> lazy;

    void split(int node) {
        lazy[2 * node] = lazy[2 * node] != lazy[node];
        lazy[2 * node + 1] = lazy[2 * node + 1] != lazy[node];
        if (lazy[node])
            tree[2 * node] = range[2 * node] - tree[2 * node];
        if (lazy[node])
            tree[2 * node + 1] = range[2 * node + 1] - tree[2 * node + 1];
        lazy[node] = false;
    }
    void merge(int node) {
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

   public:
    LazySegtree(int n, vll set_bits) {
        for (size = 1; size < n; size <<= 1)
            ;
        tree.assign(2 * size, 0);
        for (int i = 0; i < n; i++)
            tree[i + size] = set_bits[i];
        for (int i = size - 1; i > 0; i--)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        lazy.assign(2 * size, 0);
        range.assign(2 * size, 1);
        for (int i = size - 1; i >= 0; i--)
            range[i] = range[2 * i] + range[2 * i + 1];
    }

    void modify(int l, int r, bool delta, int node = 1, int x = 0, int y = -1) {
        if (!delta)
            return;
        if (y == -1)
            y = size;
        if (r <= x || l >= y)
            return;
        if (l <= x && y <= r) {
            lazy[node] = !lazy[node];
            tree[node] = range[node] - tree[node];
            return;
        }
        split(node);
        modify(l, r, delta, 2 * node, x, (x + y) / 2);
        modify(l, r, delta, 2 * node + 1, (x + y) / 2, y);
        merge(node);
    }
    int query(int l, int r, int node = 1, int x = 0, int y = -1) {
        if (y == -1)
            y = size;
        if (r <= x || l >= y)
            return 0;
        if (l <= x && y <= r) {
            return tree[node];
        }
        split(node);
        int lres = query(l, r, 2 * node, x, (x + y) / 2);
        int rres = query(l, r, 2 * node + 1, (x + y) / 2, y);
        merge(node);
        return lres + rres;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    vector<LazySegtree> seg;
    for (ll i = 0; i < 32; i++) {
        vll a_i(n);
        for (ll j = 0; j < n; j++)
            a_i[j] = (a[j] & (1ll << i)) ? 1 : 0;
        LazySegtree s_i(n, a_i);
        seg.push_back(s_i);
    }
    ll m;
    cin >> m;
    while (m--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll l, r, ans = 0;
            cin >> l >> r;
            for (int i = 0; i < 32; i++) {
                ll multiplier = seg[i].query(l - 1, r);
                ans += (1 << i) * multiplier;
            }
            cout << ans << endl;
        } else if (type == 2) {
            ll l, r, x;
            cin >> l >> r >> x;
            for (int i = 0; i < 32; i++)
                if (x & (1 << i))
                    seg[i].modify(l - 1, r, true);
        }
    }
}

// 04 10 03 13 07

//  0  0  1  1  1
//  0  1  1  0  1
//  1  0  0  1  1
//  0  1  0  1  0
//  0  0  0  0  0