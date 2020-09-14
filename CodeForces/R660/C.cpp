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
        ll h, p, p_tot = 0;
    };

    vector<Node> list;
    Node *root = nullptr;

    bool check(Node *node) {
        if ((node->p_tot - node->h < 0) || ((node->p_tot + node->h) % 2 != 0)) {
            return false;
        }
        ll good = (node->p_tot + node->h) / 2;
        ll bad = (node->p_tot - node->h) / 2;
        for (Node *next : node->adjacent) {
            if (next == node->parent)
                continue;
            if (!check(next))
                return false;
            good -= (next->p_tot + next->h) / 2;
            bad -= (next->p_tot - next->h) / 2;
        }
        return good >= 0 && bad <= node->p;
    }

    Tree(int n = 1e5) {
        list.resize(n);
        this->root = &list[0];
    }
    void add_edge(int x, int y) {
        list[x].adjacent.push_back(&list[y]);
        list[y].adjacent.push_back(&list[x]);
    }
    void __build(Node *root = nullptr) {
        if (root == nullptr)
            root = this->root;
        root->p_tot = root->p;
        for (auto child : root->adjacent) {
            if (child == root->parent)
                continue;
            child->parent = root;
            __build(child);
            root->p_tot += child->p_tot;
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
        ll n, m;
        cin >> n >> m;
        Tree tree(n);
        for (int i = 0; i < n; i++)
            cin >> tree.list[i].p;
        for (int i = 0; i < n; i++)
            cin >> tree.list[i].h;
        for (int i = 0; i < n - 1; i++) {
            ll u, v;
            cin >> u >> v;
            u--, v--;
            tree.add_edge(u, v);
        }
        tree.__build(0);
        cout << (tree.check(tree.root) ? "YES\n" : "NO\n");
    }
}