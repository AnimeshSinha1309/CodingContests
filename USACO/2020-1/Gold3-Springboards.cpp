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

template <typename Type>
class ImplicitSegupdate {
    struct Node {
        Type data = 0;
        Node *l_ptr = nullptr, *r_ptr = nullptr;
        Node *l_child() {
            if (l_ptr == nullptr)
                l_ptr = new Node, r_ptr = new Node;
            return l_ptr;
        }
        Node *r_child() {
            if (r_ptr == nullptr)
                l_ptr = new Node, r_ptr = new Node;
            return r_ptr;
        }
    };
    int size;
    Node *root;
    function<Type(Type, Type)> _setter;

   public:
    ImplicitSegupdate(int n, const function<Type(Type, Type)> &set) {
        for (size = 1; size < n; size <<= 1)
            ;
        _setter = set;
        root = new Node;
    }

    void modify(int l, int r, Type delta, Node *node = nullptr, int x = 0,
                int y = -1) {
        if (node == nullptr)
            node = root, y = size;
        if (r <= x || l >= y)
            return;
        if (l <= x && y <= r) {
            node->data = _setter(node->data, delta);
            return;
        }
        modify(l, r, delta, node->l_child(), x, (x + y) / 2);
        modify(l, r, delta, node->r_child(), (x + y) / 2, y);
    }
    Type query(int p, Node *node = nullptr, int x = 0, int y = -1) {
        if (node == nullptr)
            node = root, y = size;
        if (x == p && y == p + 1) {
            return node->data;
        }
        if (x <= p && p < (x + y) / 2)
            return _setter(node->data,
                           query(p, node->l_child(), x, (x + y) / 2));
        else
            return _setter(node->data,
                           query(p, node->r_child(), (x + y) / 2, y));
    }
};

struct Point {
    pll position;
    bool actuator;
    int index;

    friend bool operator<(const Point &a, const Point &b) {
        return a.position < b.position;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Take all the input and sort the points
    ll n, p;
    cin >> n >> p;
    vector<Point> portals(2 * p);
    for (int i = 0; i < n; i++) {
        cin >> portals[2 * i].position.first >>
            portals[2 * i].position.second >>
            portals[2 * i + 1].position.first >>
            portals[2 * i + 1].position.second;
        portals[2 * i].actuator = false;
        portals[2 * i + 1].actuator = true;
        portals[2 * i].index = i;
        portals[2 * i + 1].index = i;
    }
    vll origin_reduction(p, 0);
    // Loop over all points and compute
    for (int i = 0; i < n; i++) {
    }
}