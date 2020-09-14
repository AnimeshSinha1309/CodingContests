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

struct DisjointSetTree {
    ll comp_count;
    vector<ll> parent, comp_size, gcd;
    set<ll> roots;

    DisjointSetTree(int n) {
        comp_count = n;
        parent.resize(n);
        comp_size.resize(n, 1);
        gcd.resize(n, 0);
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

    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v)
            return false;
        parent[u] = v;
        comp_size[v] += comp_size[u];
        comp_size[u] = 0;
        gcd[v] = __gcd(gcd[u], gcd[v]);
        gcd[u] = 0;
        roots.erase(u);
        comp_count--;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vll a(n);
        cin >> a;
        vpl pairs(n);
        for (int i = 0; i < n; i++)
            pairs[i] = {a[i], i};
        sort(pairs.begin(), pairs.end());
        ll v = pairs[0].first;
        bool ans = true;
        DisjointSetTree dsu(n);
        for (int i = 0; i < n; i++) {
            if (pairs[i].second != i) {
                if (pairs[i].first % v != 0) {
                    ans = false;
                    break;
                } else {
                    dsu.gcd[i] = pairs[i].first / v;
                }
            } else
                dsu.gcd[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            dsu.merge(i, pairs[i].second);
        }
        for (auto el : dsu.gcd) {
            if (el > 1) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}