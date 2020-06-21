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

struct PushRelabel {
    struct Edge {
        ll from, to, cap, flow, index;
        Edge(ll dfrom, ll dto, ll dcap, ll dflow, ll dindex)
            : from(dfrom), to(dto), cap(dcap), flow(dflow), index(dindex) {
        }
    };

    ll size;
    vector<vector<Edge>> graph;
    vector<ll> excess;
    vector<ll> dist, active, count;
    queue<ll> q;

    PushRelabel(ll n)
        : size(n),
          graph(size),
          excess(size),
          dist(size),
          active(size),
          count(2 * size) {
    }
    void add_edge(ll from, ll to, ll cap) {
        graph[from].push_back(Edge(from, to, cap, 0, graph[to].size()));
        if (from == to)
            graph[from].back().index++;
        graph[to].push_back(Edge(to, from, 0, 0, graph[from].size() - 1));
    }
    void __enqueue(ll v) {
        if (!active[v] && excess[v] > 0) {
            active[v] = true;
            q.push(v);
        }
    }
    void __push(Edge &e) {
        ll amt = ll(min(excess[e.from], ll(e.cap - e.flow)));
        if (dist[e.from] <= dist[e.to] || amt == 0)
            return;
        e.flow += amt;
        graph[e.to][e.index].flow -= amt;
        excess[e.to] += amt;
        excess[e.from] -= amt;
        __enqueue(e.to);
    }
    void __gap(ll k) {
        for (ll v = 0; v < size; v++) {
            if (dist[v] < k)
                continue;
            count[dist[v]]--;
            dist[v] = max(dist[v], size + 1);
            count[dist[v]]++;
            __enqueue(v);
        }
    }
    void __relabel(ll v) {
        count[dist[v]]--;
        dist[v] = 2 * size;
        for (ll i = 0; i < (ll)graph[v].size(); i++)
            if (graph[v][i].cap - graph[v][i].flow > 0)
                dist[v] = min(dist[v], dist[graph[v][i].to] + 1);
        count[dist[v]]++;
        __enqueue(v);
    }
    void __discharge(ll v) {
        for (ll i = 0; excess[v] > 0 && i < (ll)graph[v].size(); i++)
            __push(graph[v][i]);
        if (excess[v] > 0) {
            if (count[dist[v]] == 1)
                __gap(dist[v]);
            else
                __relabel(v);
        }
    }
    ll max_flow(ll s, ll t) {
        count[0] = size - 1;
        count[size] = 1;
        dist[s] = size;
        active[s] = active[t] = true;
        for (ll i = 0; i < (ll)graph[s].size(); i++) {
            excess[s] += graph[s][i].cap;
            __push(graph[s][i]);
        }
        while (!q.empty()) {
            ll v = q.front();
            q.pop();
            active[v] = false;
            __discharge(v);
        }
        ll totflow = 0;
        for (ll i = 0; i < (ll)graph[s].size(); i++)
            totflow += graph[s][i].flow;
        return totflow;
    }
};

int main(void) {
    // freopen("attack.in", "r", stdin);
    // freopen("attack.out", "w", stdout);
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;

    PushRelabel a1(n), a2(n);
    vpl edges(m);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        a1.add_edge(u, v, w);
        a2.add_edge(u, v, w);
        edges[i] = {u, v};
    }
    a1.max_flow(s, t);
    a2.max_flow(t, s);

    vbl half_1(n), half_2(n);
    for (int i = 0; i < n; i++) {
        half_1[i] = a1.dist[i] >= n;
        half_2[i] = a2.dist[i] >= n;
    }

    for (int i = 0; i < n; i++) {
        for (int i = 0; i < n; i++) {
            if ((half_1[edges[i].first] != half_1[edges[i].second]) ==
                (half_2[edges[i].first] != half_2[edges[i].second])) {
                cout << "AMBIGUOUS" << endl;
                exit(0);
            }
        }
    }
    cout << "UNIQUE\n";
}
