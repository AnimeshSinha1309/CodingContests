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
        ll max_component = 0;
    };

    vector<Node> list;
    Node *root = nullptr;
    vector<vector<Node *>> __anc;

    Tree(int n = 1e5) {
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
            maximize(root->max_component, child->subtree_size);
        }
        maximize(root->max_component, (ll)list.size() - root->subtree_size);
        root->end_time = time;
        return time;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Tree tree(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            tree.add_edge(a - 1, b - 1);
        }
        tree.__build();
        ll max_1 = -1, max_2 = -1, val_1 = INT64_MAX, val_2 = INT64_MAX;
        for (int i = 0; i < n; i++) {
            if (tree.list[i].max_component <= val_1)
                max_2 = max_1, val_2 = val_1, max_1 = i,
                val_1 = tree.list[i].max_component;
            else if (tree.list[i].max_component <= val_2)
                max_2 = i, val_2 = tree.list[i].max_component;
        }
        if (val_1 == val_2) {
            for (Tree::Node *node : tree.list[max_2].adjacent) {
                if (node->index != max_1) {
                    // Pick up someone on max_2 side and connect to max_1
                    cout << node->index + 1 << ' ' << max_2 + 1 << '\n';
                    cout << node->index + 1 << ' ' << max_1 + 1 << '\n';
                    break;
                }
            }
        } else {
            cout << 1 << ' ' << tree.list[0].adjacent[0]->index + 1 << '\n';
            cout << 1 << ' ' << tree.list[0].adjacent[0]->index + 1 << '\n';
        }
    }
}