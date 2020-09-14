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

vector<int> result;

class Graph {
   public:
    struct Node {
        int index;
        vll adjacent;
    };
    vector<Node> list;
    int n;
    Graph(int n) {
        list.resize(n);
        for (int i = 0; i < n; i++)
            list[i].index = i;
        this->n = n;
    }
    void add_edge(int u, int v) {
        list[u].adjacent.emplace_back(v);
    }

    // Returns sorted vector of indices
    void topological_sort() {
        vector<int> in_degree(list.size(), 0);
        result.reserve(list.size());
        for (auto node : list)
            for (auto route : node.adjacent)
                in_degree[route]++;
        queue<int> process;
        for (int i = 0; i < list.size(); i++) {
            if (in_degree[i] == 0) {
                process.push(i);
                result.push_back(i);
            }
        }
        while (!process.empty()) {
            int processing = process.front();
            process.pop();
            for (auto route : list[processing].adjacent) {
                in_degree[route]--;
                if (in_degree[route] == 0) {
                    process.push(route);
                    result.push_back(route);
                }
            }
        }
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vll a(n), b(n);
    cin >> a >> b;
    Graph g(n);
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            g.add_edge(i, b[i] - 1);
        }
    }
    g.topological_sort();
    ll ans = 0;
    vll idx;
    for (int i = 0; i < n; i++) {
        if (a[result[i]] >= 0) {
            ans += a[result[i]];
            a[b[result[i]] - 1] += a[result[i]];
            idx.push_back(result[i]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[result[i]] < 0) {
            ans += a[result[i]];
            a[b[result[i]] - 1] += a[result[i]];
            idx.push_back(result[i]);
        }
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << idx[i] + 1 << ' ';
    }
    cout << endl;
}