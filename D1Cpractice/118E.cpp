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

class Graph {
   public:
    enum NodeColor { UNVISITED, VISITING, VISITED };
    enum EdgeColor { SPAN_EDGE, BACK_EDGE, CROSS_EDGE, DUPLICATE_EDGE };

    struct Edge;
    struct Node;
    int n;
    vector<Node> list;

    struct Edge {
        Node *to;
        bool bridge = false;
        EdgeColor _color = DUPLICATE_EDGE;
        Edge(Node *dest) {
            to = dest;
        }
    };
    struct Node {
        int index;
        vector<Edge> adj;
        NodeColor _color;
        int _incoming_back_edges = 0;
        bool _dfs_visited = false;
    };

    Graph(int n) {
        list.resize(n);
        for (int i = 0; i < n; i++)
            list[i].index = i;
        this->n = n;
    }
    void add_edge(int u, int v) {
        list[u].adj.emplace_back(&list[v]);
        list[v].adj.emplace_back(&list[u]);
    }

    int __dfs_bridges(Node *v, set<pll> &bridges, Node *p = nullptr) {
        v->_color = VISITING;
        int back_edge_count = 0;
        for (Edge &edge : v->adj) {
            if (edge.to == p) {
                continue;
            } else if (edge.to->_color == VISITING) {
                edge._color = BACK_EDGE;
                back_edge_count++;
                edge.to->_incoming_back_edges++;
            } else if (edge.to->_color == UNVISITED) {
                edge._color = SPAN_EDGE;
                back_edge_count += __dfs_bridges(edge.to, bridges, v);
            }
        }
        back_edge_count -= v->_incoming_back_edges;
        if (back_edge_count == 0 && p != nullptr)
            bridges.insert({p->index, v->index});
        v->_color = VISITED;
        return back_edge_count;
    }

    set<pll> _build_bridges() {
        int timer = 0;
        set<pll> bridges;
        for (int i = 0; i < n; ++i)
            list[i]._color = UNVISITED;
        for (int i = 0; i < n; ++i) {
            if (list[i]._color == UNVISITED)
                __dfs_bridges(&list[i], bridges);
        }
        return bridges;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Take the graph as input
    ll n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u - 1, v - 1);
    }
    // Printing the bridges
    if (g._build_bridges().empty()) {
        for (auto node : g.list) {
            for (auto edge : node.adj) {
                if (edge._color != Graph::DUPLICATE_EDGE)
                    cout << node.index + 1 << " " << edge.to->index + 1 << endl;
            }
        }
    } else {
        cout << 0 << endl;
    }
}