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
        int subtree_size = 1;
        int depth = 0;
        int index = INT32_MAX;
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
        for (auto child : root->adjacent) {
            if (child == root->parent)
                continue;
            child->parent = root;
            child->depth = root->depth + 1;
            time = __build(child, time + 1);
            root->subtree_size += child->subtree_size;
        }
        return time;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    Tree tree(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree.add_edge(a - 1, b - 1);
    }
    tree.__build();
    ll ans = 0;
    priority_queue<ll> q;
    for (Tree::Node node : tree.list) {
        q.push(node.depth - (node.subtree_size - 1));
    }
    for (int i = 0; i < k; i++) {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
}