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

struct Dinic {
    struct Edge {
        int u, v;
        ll cap, flow;
        Edge() : u(0), v(0), cap(0), flow(0) {
        }
        Edge(int uu, int vv, ll ccap) : u(uu), v(vv), cap(ccap), flow(0) {
        }
    };

    int size;
    vector<Edge> edges;
    vector<vector<int>> adjacency;
    vector<int> d, pt;
    Dinic(int NN) : size(NN), edges(0), adjacency(size), d(size), pt(size) {
    }
    int add_edge(int u, int v, ll cap_f, ll cap_r = 0) {
        if (u != v) {
            edges.emplace_back(Edge(u, v, cap_f));
            adjacency[u].emplace_back(edges.size() - 1);
            edges.emplace_back(Edge(v, u, cap_r));
            adjacency[v].emplace_back(edges.size() - 1);
            return (int)edges.size() - 2;
        }
        return -1;
    }
    bool __bfs(int source, int sink) {
        queue<int> q({source});
        fill(d.begin(), d.end(), size + 1);
        d[source] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == sink)
                break;
            for (int k : adjacency[u]) {
                Edge &e = edges[k];
                if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
                    d[e.v] = d[e.u] + 1;
                    q.emplace(e.v);
                }
            }
        }
        return d[sink] != size + 1;
    }

    ll __dfs(int u, int sink, ll flow = -1) {
        if (u == sink || flow == 0)
            return flow;
        for (int &i = pt[u]; i < (int)adjacency[u].size(); ++i) {
            Edge &e = edges[adjacency[u][i]];
            Edge &oe = edges[adjacency[u][i] ^ 1];
            if (d[e.v] == d[e.u] + 1) {
                ll amt = e.cap - e.flow;
                if (flow != -1 && amt > flow)
                    amt = flow;
                if (ll pushed = __dfs(e.v, sink, amt)) {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    ll max_flow(int source, int sink) {
        ll total = 0;
        while (__bfs(source, sink)) {
            fill(pt.begin(), pt.end(), 0);
            while (ll flow = __dfs(source, sink))
                total += flow;
        }
        return total;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vll a(n), b(n);
    cin >> a >> b;

    Dinic d = Dinic(2 * n + 2);
    int source_node = 2 * n + 0, sink_node = 2 * n + 1;

    mll edges(n, vll(n, -1));
    for (int i = 0; i < m; i++) {
        pll e;
        cin >> e.first >> e.second;
        e.first--, e.second--;
        edges[e.first][e.second] = d.add_edge(e.first, e.second + n, 100);
        edges[e.second][e.first] = d.add_edge(e.second, e.first + n, 100);
    }
    for (int i = 0; i < n; i++) {
        edges[i][i] = d.add_edge(i, i + n, 100);
        d.add_edge(source_node, i, a[i]);
        d.add_edge(i + n, sink_node, b[i]);
    }
    ll soldiers_in = accumulate(a.begin(), a.end(), 0),
       soldiers_out = accumulate(b.begin(), b.end(), 0);
    if (d.max_flow(source_node, sink_node) != soldiers_in ||
        soldiers_in != soldiers_out) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (edges[i][j] == -1)
                    cout << "0 ";
                else
                    cout << d.edges[edges[i][j]].flow << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
