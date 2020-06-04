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
ostream &operator<<(ostream &out, bool &val) {
    if (val)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return out;
}

class Graph {
   public:
    enum NodeColor { VISITED, VISITING, UNVISITED };
    struct Node {
        int index;
        vector<pair<long long, long long>> adjacent;
        NodeColor _color = UNVISITED;
    };
    vector<Node> list;
    Graph(int n) {
        list.resize(n);
        for (int i = 0; i < n; i++)
            list[i].index = i;
    }
    void add_edge(int u, int v, long long w = 0) {
        list[u].adjacent.emplace_back(v, 1);
        list[v].adjacent.emplace_back(u, 1);
    }

    pair<vll, vll> dijkstra(vll from) {
        ll n = this->list.size();
        vll dist(n, INT64_MAX), parent(n, INT32_MAX);
        priority_queue<pll, vpl, greater<>> q;
        for (auto index : from) {
            dist[index] = 0;
            q.emplace(index, 0);
        }
        while (!q.empty()) {
            pll top = q.top();
            q.pop();
            if (top.second > dist[top.first])
                continue;
            for (auto edge : list[top.first].adjacent) {
                if (top.second + edge.second < dist[edge.first]) {
                    dist[edge.first] = top.second + edge.second;
                    parent[edge.first] = top.first - 1;
                    q.emplace(edge.first, top.second + edge.second);
                }
            }
        }
        return {dist, parent};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        g.add_edge(u - 1, v - 1);
    }
    ll s1, t1, l1, s2, t2, l2;
    cin >> s1 >> t1 >> l1;
    cin >> s2 >> t2 >> l2;
    s1--;
    s2--;
    t1--;
    t2--;
    ll ans = INT32_MAX;
    mll d(n);
    for (int i = 0; i < n; i++) {
        d[i] = g.dijkstra({i}).first;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll dist1 = min(d[s1][i] + d[i][j] + d[j][t1],
                           d[s1][j] + d[j][i] + d[i][t1]);
            ll dist2 = min(d[s2][i] + d[i][j] + d[j][t2],
                           d[s2][j] + d[j][i] + d[i][t2]);
            if (dist1 <= l1 && dist2 <= l2)
                minimize(ans, dist1 + dist2 - d[i][j]);
        }
    }
    if (d[s1][t1] <= l1 && d[s2][t2] <= l2)
        minimize(ans, d[s1][t1] + d[s2][t2]);
    cout << (ans < INT32_MAX ? m - ans : -1) << endl;
}