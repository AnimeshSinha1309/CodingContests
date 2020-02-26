#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
    };

    vector<Node> list;
    Node *root = nullptr;
    vector<vector<Node *>> __anc;

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

    Node *lca(Node *a, Node *b) {
        if (b->depth > a->depth)
            swap(a, b);
        for (int ptr = __anc[0].size() - 1; a->depth > b->depth && ptr >= 0;
             ptr--) {
            if (__anc[a->index][ptr] != nullptr &&
                __anc[a->index][ptr]->depth >= b->depth)
                a = __anc[a->index][ptr];
        }
        if (a == b)
            return a;
        for (long step = __anc[0].size() - 1; step >= 0; step--) {
            if (__anc[a->index][step] != __anc[b->index][step])
                a = __anc[a->index][step], b = __anc[b->index][step];
        }
        return a->parent;
    }
    Node *ancestor(Node *a, int degree) {
        ll target_depth = a->depth - degree;
        for (int ptr = __anc[0].size() - 1; a->depth > target_depth && ptr >= 0;
             ptr--) {
            if (__anc[a->index][ptr] != nullptr &&
                __anc[a->index][ptr]->depth >= target_depth)
                a = __anc[a->index][ptr];
        }
        return a;
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
    void __build_lca_matrix() {
        int n = list.size();
        __anc = *new vector<vector<Node *>>(
            n, vector<Node *>(log2(n) + 1, nullptr));
        for (int i = 0; i < list.size(); i++)
            __anc[i][0] = list[i].parent;
        for (int level = 1; level < __anc[0].size(); level++)
            for (int i = 0; i < list.size(); i++) {
                if (__anc[i][level - 1] == nullptr)
                    continue;
                __anc[i][level] = __anc[__anc[i][level - 1]->index][level - 1];
            }
    }
};

int main() {
    int n;
    cin >> n;
    Tree tree(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree.add_edge(a - 1, b - 1);
    }
    tree.__build();
    tree.__build_lca_matrix();
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        Tree::Node *x = &tree.list[a - 1], *y = &tree.list[b - 1];
        if (a == b) {
            cout << n << endl;
        } else if (x->depth == y->depth) {
            int lca_depth = tree.lca(x, y)->depth;
            ll ans = tree.root->subtree_size -
                     tree.ancestor(x, x->depth - lca_depth - 1)->subtree_size -
                     tree.ancestor(y, y->depth - lca_depth - 1)->subtree_size;
            cout << ans << endl;
        } else {
            if (x->depth < y->depth)
                swap(x, y);
            int lca_depth = tree.lca(x, y)->depth;
            int dist = x->depth + y->depth - 2 * lca_depth;
            if (dist % 2 == 1) {
                cout << 0 << endl;
                continue;
            }
            Tree::Node *center = tree.ancestor(x, dist / 2 - 1);
            ll ans = center->parent->subtree_size - center->subtree_size;
            cout << ans << endl;
        }
    }
}
