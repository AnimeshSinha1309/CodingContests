#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef long double ld;
typedef vector<long double> vld;
typedef vector<vector<long double>> mld;

class Tree {
   public:
    struct Node {
        vector<Node *> adjacent;
        Node *parent = nullptr;
        ll start_time = 0, end_time = 0, depth = 0;
    };

    vector<Node> list;
    ll n;
    Node *root = nullptr;

    Tree(ll n = 1e5) {
        list.resize(n);
        this->root = &list[0];
        this->n = n;
    }
    void add_edge(ll x, ll y) {
        list[x].adjacent.push_back(&list[y]);
        list[y].adjacent.push_back(&list[x]);
    }
    ll __build(Node *root, ll time) {
        root->start_time = time;
        for (auto child : root->adjacent) {
            if (child == root->parent)
                continue;
            child->parent = root;
            child->depth = root->depth + 1;
            time = __build(child, time + 1);
        }
        root->end_time = time;
        return time;
    }

    ll solve(const ll a, const ll b) {
        mll level_a(a), level_b(b);
        for (auto el : list) {
            level_a[el.depth % a].push_back(el.start_time);
            level_b[el.depth % b].push_back(el.start_time);
        }
        for (auto &l : level_a)
            sort(l.begin(), l.end());
        for (auto &l : level_b)
            sort(l.begin(), l.end());
        ll count_a = 0, count_b = 0, count_ab = 0;
        ll target;
        for (auto el : list) {
            target = el.depth % a;
            ll val_a = upper_bound(level_a[target].begin(),
                                   level_a[target].end(), el.end_time) -
                       lower_bound(level_a[target].begin(),
                                   level_a[target].end(), el.start_time);
            target = el.depth % b;
            ll val_b = upper_bound(level_b[target].begin(),
                                   level_b[target].end(), el.end_time) -
                       lower_bound(level_b[target].begin(),
                                   level_b[target].end(), el.start_time);
            count_a += val_a;
            count_b += val_b;
            count_ab += val_a * val_b;
        }
        ll tot = (count_a + count_b) * n - count_ab;
        return tot;
    }
};

int main() {
    ll tests;
    cin >> tests;
    for (ll test = 1; test <= tests; test++) {
        ll n, a, b;
        cin >> n >> a >> b;
        Tree t(n);
        for (ll i = 1; i < n; i++) {
            ll p;
            cin >> p;
            t.add_edge(i, p - 1);
        }
        t.__build(t.root, 0);
        ll tot = t.solve(a, b);
        ld ans = (ld)tot / (ld)(n * n);
        cout << setprecision(10) << fixed << "Case #" << test << ": " << ans
             << endl;
    }
}