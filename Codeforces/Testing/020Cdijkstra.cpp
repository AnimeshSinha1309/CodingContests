// Proof of Validity
// #dijkstra

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

template<typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
    ll n = vec.size();
    for (int i = 0; i < n; i++)
        in >> vec[i];
    return in;
}

template<typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    out << endl;
    return out;
}

class Graph {
public:
    enum NodeColor {
        VISITED, VISITING, UNVISITED
    };
    struct Node {
        int index;
        vpl adjacent;
        NodeColor color = UNVISITED;
    };
    vector<Node> list;
    int n;

    explicit Graph(int n) {
        list.resize(n);
        for (int i = 0; i < n; i++)
            list[i].index = i;
        this->n = n;
    }

    void add_edge(int u, int v, long long w = 1) {
        list[u].adjacent.emplace_back(v, w);
        list[v].adjacent.emplace_back(u, w);
    }

    pair<vll, vll> dijkstra(vll from) {
        vll dist(n, INT64_MAX), parent(n, INT32_MAX);
        priority_queue<pll, vpl, greater<>> q;
        for (auto index : from)
            dist[index] = 0, q.emplace(0, index);
        while (!q.empty()) {
            pll top = q.top();
            q.pop();
            if (top.first > dist[top.second])
                continue;
            for (auto edge : list[top.second].adjacent)
                if (top.first + edge.second < dist[edge.first])
                    dist[edge.first] = top.first + edge.second,
                            parent[edge.first] = top.second,
                            q.emplace(top.first + edge.second, edge.first);
        }
        return {dist, parent};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Take input and pass to Dijkstra
    ll n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u - 1, v - 1, w);
    }
    pair<vll, vll> d = g.dijkstra({0});
    // Traceback path using parents on the stack
    stack<ll> res;
    for (ll current = n - 1; current < n; current = d.second[current])
        res.push(current + 1);
    // Print the result
    if (d.first[n - 1] == INT64_MAX) {
        cout << -1 << endl;
    } else {
        for (; !res.empty(); res.pop())
            cout << res.top() << " ";
        cout << endl;
    }
}