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
        vll incoming = vll(9, -1);
        NodeColor color = UNVISITED;
    };
    vector<Node> list;
    int n;
    mbl mat = mbl(81, vbl(81, true));

    Graph(int n) {
        list.resize(n);
        for (int i = 0; i < n; i++)
            list[i].index = i;
        this->n = n;
    }
    void add_edge(int u, int v, long long w = 1) {
        list[u].adjacent.emplace_back(w, v);
    }

    void build_graph() {
        for (int i = 0; i < n; i++) {
            sort(list[i].adjacent.begin(), list[i].adjacent.end());
        }
        for (int i = 0; i < n; i++) {
            int degree = list[i].adjacent.size();
            for (int j = 0; j < degree; j++) {
                int next = list[i].adjacent[j].first;
                if (list[next].incoming[degree] != -1 &&
                    list[next].incoming[degree] != j + 1) {
                    cout << 0 << endl;
                    exit(0);
                }
                list[next].incoming[degree] = j + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int x = 0; x < 9; x++) {
                for (int y = x + 1; y < 9; y++) {
                    int x_ = list[i].incoming[x];
                    int y_ = list[i].incoming[y];
                    if (x_ != -1 && y_ != -1)
                        mat[x_ + x * 9][y_ + y * 9] = false;
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m, k;
    cin >> n >> m >> k;
    Graph g(n);
    for (int i = 0; i < n; i++) {
        ll u, v, w;
        g.add_edge(u - 1, v - 1, w);
    }
}