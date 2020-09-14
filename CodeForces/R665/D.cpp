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

class Tree {
   public:
    struct Node {
        vector<Node *> adjacent;
        Node *parent = nullptr;
        ll subtree_size = 1;
    };

    ll n;
    vector<Node> list;
    Node *root = nullptr;
    vector<vector<Node *>> __anc;

    Tree(ll n = 1e5) {
        this->n = n;
        list.resize(n);
        this->root = &list[0];
    }
    void add_edge(int x, int y) {
        list[x].adjacent.push_back(&list[y]);
        list[y].adjacent.push_back(&list[x]);
    }

    void __build(Node *root) {
        for (auto child : root->adjacent) {
            if (child == root->parent)
                continue;
            child->parent = root;
            __build(child);
            root->subtree_size += child->subtree_size;
        }
    }
    void dfs(vll &list, Node *root) {
        for (auto child : root->adjacent) {
            if (child == root->parent)
                continue;
            list.push_back((n - child->subtree_size) * child->subtree_size);
            dfs(list, child);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        // Make the tree
        int n;
        cin >> n;
        Tree tree(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            tree.add_edge(a - 1, b - 1);
        }
        tree.__build(tree.root);
        // Get the prime factors
        int m;
        cin >> m;
        vll p(m);
        cin >> p;
        sort(p.rbegin(), p.rend());
        // Get the multiplicities
        vll v;
        v.reserve(n - 1);
        tree.dfs(v, tree.root);
        sort(v.rbegin(), v.rend());
        // Print the answer
        ll ans = 0;
        for (int i = 0; i < n - 1; i++) {
            v[i] %= MOD;
            if (i < m) {
                ans = (ans + (p[i] * v[i]) % MOD) % MOD;
            } else {
                ans = (ans + v[i]) % MOD;
            }
        }
        cout << ans << endl;
    }
}