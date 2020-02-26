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

class Tree {
   public:
    struct Node {
        int index;
        vector<Node*> adjacent;
        Node* parent = nullptr;
        long long start_time = 0, end_time = 0, depth = 0;
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
            child->depth = root->depth + 1;
            time = __build(child, time + 1);
        }
        root->end_time = time;
        return time;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // Build a Tree from the input
    Tree tree(n);
    for (int u = 1; u < n; u++) {
        int v;
        scanf("%d", &v);
        tree.add_edge(u, v - 1);
    }
    tree.__build();
    char st[n];
    scanf("%s", st);
    // Make a matrix of Letters * Depth * Start-Time
    ll max_depth = 0;
    for (Tree::Node n : tree.list)
        maximize(max_depth, n.depth);
    vector<mll> letters(26, mll(max_depth + 1));
    for (int i = 0; i < n; i++) {
        letters[st[i] - 'a'][tree.list[i].depth].push_back(
            tree.list[i].start_time);
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j <= max_depth; j++) {
            sort(letters[i][j].begin(), letters[i][j].end());
        }
    }
    // Process the queries
    for (int q = 0; q < m; q++) {
        int v, h;
        scanf("%d %d", &v, &h);
        v--;
        h--;
        if (h > max_depth) {
            printf("No\n");
            continue;
        }
        ll count_odd = 0;
        for (int i = 0; i < 26; i++) {
            auto l = lower_bound(letters[i][h].begin(), letters[i][h].end(),
                                 tree.list[v].start_time);
            auto r = upper_bound(letters[i][h].begin(), letters[i][h].end(),
                                 tree.list[v].end_time);
            int diff = r - l;
            if (diff % 2 == 1)
                count_odd++;
        }
        printf(count_odd <= 1 ? "Yes\n" : "No\n");
    }
}