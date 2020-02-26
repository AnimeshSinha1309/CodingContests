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
        long long start_time = 0, end_time = 0, subtree_size = 1;
        unsigned long depth = 0, height = 0;
        unsigned long index = INT32_MAX;
        bool black = false;
    };

    vector<Node> list;
    Node *root = nullptr;

    Tree(int n) {
        list.resize(n);
        this->root = &list[0];
        for (int i = 0; i < n; i++)
            list[i].index = i;
    }
    void add_edge(int x, int y) {
        list[x].adjacent.push_back(&list[y]);
        list[y].adjacent.push_back(&list[x]);
    }

    int __build(Node *root = nullptr, int time = 0) {
        if (root == nullptr)
            root = this->root;
        root->start_time = time;
        for (auto child : root->adjacent) {
            if (child == root->parent)
                continue;
            child->parent = root;
            child->depth = root->depth + 1;
            time = __build(child, time + 1);
            root->height = max(root->height, child->height + 1);
            root->subtree_size += child->subtree_size;
        }
        root->end_time = time;
        return time;
    }
};

long long mod_power(long long a, long long b, long long MOD) {
    long long cumulative = a, result = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            result = (result * cumulative) % MOD;
        cumulative = (cumulative * cumulative) % MOD;
    }
    return result;
}
long long mod_inverse(long long a, long long MOD) {
    return mod_power(a, MOD - 2, MOD);
}

#define WHITE first
#define BLACK second

pll dp(Tree::Node *root) {
    pll res = {1, 1};
    if (root->black) {
        for (auto child : root->adjacent) {
            if (child == root->parent)
                continue;
            pll ch = dp(child);
            res.WHITE = (res.WHITE * ch.WHITE) % MOD;
            res.BLACK = (res.BLACK * ch.WHITE) % MOD;
        }
    } else {
        ll sum_term = 0;
        for (auto child : root->adjacent) {
            if (child == root->parent)
                continue;
            pll ch = dp(child);
            res.WHITE = (res.WHITE * ch.WHITE) % MOD;
            res.BLACK = (res.first * ch.WHITE) % MOD;
            sum_term = (sum_term + ch.BLACK * mod_inverse(ch.WHITE, MOD)) % MOD;
        }
        res.WHITE = (res.WHITE + 1) % MOD;
        res.BLACK = (res.BLACK * sum_term) % MOD;
        cout << ">>> " << root->index << " " << res.WHITE << " " << res.BLACK
             << endl;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    Tree tree(n);
    for (int i = 1; i < n; i++) {
        int v;
        cin >> v;
        tree.add_edge(i, v);
    }
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        tree.list[i].black = (temp == 1);
    }
    tree.__build();
    cout << dp(tree.root).BLACK << endl;
}