#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long long, long long> pll;
#define minimize(var, val) (var = min((val), var))
long long MOD = 1e9 + 7;

class Tree {
   public:
    struct Node {
        int index;
        vector<Node*> adjacent;
        Node* parent = nullptr;
        long long start_time = 0, end_time = 0;
        ll dp_subtree = 1, dp_supertree = 1;
    };

    vector<Node> list;
    Node* root = nullptr;

    explicit Tree(int n) {
        list = vector<Node>(n);
        for (int i = 0; i < n; i++)
            list[i].index = i;
        root = &list[0];
    }
    void add_edge(int x, int y) {
        assert(x < list.size() && y < list.size());
        list[x].adjacent.push_back(&list[y]);
        list[y].adjacent.push_back(&list[x]);
    }
    int __build(Node* root = nullptr, int time = 0) {
        if (root == nullptr)
            root = this->root;
        root->start_time = time;
        for (auto child : root->adjacent) {
            if (child == root->parent)
                continue;
            child->parent = root;
            time = __build(child, time + 1);
        }
        root->end_time = time;
        return time;
    }
};

// Return ways with black root in subtree
ll dp_sub(Tree::Node* root) {
    root->dp_subtree = 1;
    for (auto child : root->adjacent) {
        if (child == root->parent)
            continue;
        root->dp_subtree = (root->dp_subtree * (dp_sub(child) + 1)) % MOD;
    }
    return root->dp_subtree;
}

// Propagates number of ways to children
void dp_sup(Tree::Node* root) {
    ll ways_in_prefix = 1, ways_in_suffix = 1, n = root->adjacent.size();
    for (int i = 0; i < n; i++) {
        if (root->adjacent[i] == root->parent)
            continue;
        root->adjacent[i]->dp_supertree =
            (root->adjacent[i]->dp_supertree * ways_in_prefix) % MOD;
        ways_in_prefix =
            (ways_in_prefix * (root->adjacent[i]->dp_subtree + 1)) % MOD;
    }
    for (int j = n - 1; j >= 0; j--) {
        if (root->adjacent[j] == root->parent)
            continue;
        root->adjacent[j]->dp_supertree =
            (root->adjacent[j]->dp_supertree * ways_in_suffix) % MOD;
        ways_in_suffix =
            (ways_in_suffix * (root->adjacent[j]->dp_subtree + 1)) % MOD;
    }
    for (auto child : root->adjacent) {
        if (child == root->parent)
            continue;
        child->dp_supertree =
            (child->dp_supertree * root->dp_supertree + 1) % MOD;
        dp_sup(child);
    }
}

int main() {
    int n;
    cin >> n >> MOD;
    // Build a Tree from the input
    Tree tree(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u - 1, v - 1);
    }
    tree.__build();
    // Call DP and output
    dp_sub(tree.root);
    dp_sup(tree.root);
    for (int i = 0; i < n; i++)
        cout << (tree.list[i].dp_subtree * tree.list[i].dp_supertree) % MOD
             << endl;
}