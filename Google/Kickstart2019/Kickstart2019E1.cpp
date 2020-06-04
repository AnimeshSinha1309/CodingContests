// Accepted
// Tags: #Graph #DSU

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
    enum NodeColor { VISITED, VISITING, UNVISITED };
    struct Node {
        int index;
        vpl adjacent;
        NodeColor _color = UNVISITED;
    };
    vector<Node> list;
    int n;

    void add_edge(int u, int v, long long w = 1) {
        list[u].adjacent.emplace_back(v, w);
        list[v].adjacent.emplace_back(u, w);
    }

    Graph(int n) {
        list.resize(n);
        for (int i = 0; i < n; i++)
            list[i].index = i;
        this->n = n;
    }

    mll components() {
        vbl visited(n);
        mll result(0);
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            vll component;
            stack<ll> process;
            process.push(list[i].index);
            component.push_back(i);
            visited[i] = true;
            while (!process.empty()) {
                ll processing = process.top();
                process.pop();
                for (pll neighbor : list[processing].adjacent) {
                    if (!visited[neighbor.first]) {
                        process.push(neighbor.first);
                        component.push_back(neighbor.first);
                        visited[neighbor.first] = true;
                    }
                }
            }
            result.push_back(component);
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unsigned int testCases;
    cin >> testCases;
    for (int testCase = 1; testCase <= testCases; testCase++) {
        ll n, m;
        cin >> n >> m;
        Graph g(n);
        for (int i = 0; i < m; i++) {
            ll u, v;
            cin >> u >> v;
            g.add_edge(u - 1, v - 1);
        }
        ll black = g.components().size() - 1;
        cout << "Case #" << testCase << ": " << (n - 1) + black << endl;
    }
}