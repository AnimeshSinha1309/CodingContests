#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long long, long long> pll;
#define minimize(var, val) (var = min((val), var))
const long long MOD = 1e9 + 7;

#define BLACK first
#define WHITE second

class Tree {
   public:
    struct Node {
        int index;
        vector<Node*> adjacent;
        Node* parent = nullptr;
        long long start_time = 0, end_time = 0;
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

// Return pair {ways with black root, ways with white root}
pll dp(Tree::Node* root) {
    pll ans = {1, 1};
    for (auto child : root->adjacent) {
        if (child == root->parent)
            continue;
        pll dp_ans = dp(child);
        ans.BLACK = (ans.BLACK * dp_ans.WHITE) % MOD;
        ans.WHITE = (ans.WHITE * (dp_ans.WHITE + dp_ans.BLACK)) % MOD;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    Tree tree(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u - 1, v - 1);
    }
    tree.__build();
    pll ans = dp(tree.root);
    cout << (ans.first + ans.second) % MOD << endl;
}

#ifndef CODE_TREE_H
#define CODE_TREE_H

#include <iostream>
#include <vector>
using namespace std;

template <class Type>
class Tree {
   public:
    struct Node {
        Type data;
        vector<Node*> adjacent;
        Node* parent = nullptr;
        long long start_time = 0, end_time = 0;
    };

    vector<Node> list;
    Node* root = nullptr;

    explicit Tree(vector<Type> data) {
        list.reserve(data.size());
        for (auto datum : data) {
            list.emplace_back(datum);
        }
    }
    Tree(vector<Type> data, vector<pair<int, int>> edges) {
        list.reserve(data.size());
        for (auto datum : data) {
            list.emplace_back(datum);
        }
        for (auto edge : edges) {
            add_edge(edge.first, edge.second);
        }
        __build();
    }
    void add_edge(int x, int y) {
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

#endif  // CODE_TREE_H
