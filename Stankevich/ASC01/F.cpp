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

struct Circle {
    ld x, y;
    ld r;
};
#define sq(x) ((x) * (x))

struct DisjointSetTree {
    ll comp_count;
    vector<ll> parent, comp_size;
    set<ll> roots;
    vector<bool> cut;
    DisjointSetTree(int n) {
        comp_count = n;
        parent.resize(n);
        comp_size.resize(n, 1);
        cut.resize(n, false);
        iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < n; i++) {
            roots.insert(i);
        }
    }

    int find(int u) {
        if (parent[u] == u)
            return parent[u];
        return parent[u] = find(parent[u]);
    }

    bool merge(int u, int v, bool intercept) {
        u = find(u), v = find(v);
        if (u == v) {
            return cut[u] != intercept;
        }
        parent[u] = v;
        comp_size[v] += comp_size[u];
        comp_size[u] = 0;
        roots.erase(u);
        comp_count--;
        cut[v] = ((cut[v] != cut[u]) != intercept);
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("out.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    ll n;
    cin >> n;
    vector<Circle> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y >> a[i].r;
    Circle kobok;
    cin >> kobok.x >> kobok.y >> kobok.r;
    for (int i = 0; i < n; i++)
        a[i].x -= kobok.x, a[i].y -= kobok.y;
    DisjointSetTree dsu(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sq(a[i].x - a[j].x) + sq(a[i].y - a[j].y) <
                sq(a[i].r + a[j].r + 2 * kobok.r)) {
                Circle c1 = a[i], c2 = a[j];
                if (c1.x > c2.x)
                    swap(c1, c2);
                bool cuts = c1.x <= 0 && c2.x > 0 && c1.x * c2.y < c2.x * c1.y;
                if (dsu.merge(i, j, cuts)) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
}