#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
#define minimize(a, b) (a = min(a, b))
#define maximize(a, b) (a = max(a, b))
const long long MOD = 1e9 + 7;

template <typename Type>
class ImplicitSegupdate {
    struct Node {
        Type data = 0;
        Node *l_ptr = nullptr, *r_ptr = nullptr;
        Node *l_child() {
            if (l_ptr == nullptr) {
                l_ptr = new Node;
                r_ptr = new Node;
            }
            return l_ptr;
        }
        Node *r_child() {
            if (r_ptr == nullptr) {
                l_ptr = new Node;
                r_ptr = new Node;
            }
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
        if (x <= p && p < (x + y) / 2) return _setter(
            node->data, query(p, node->l_child(), x, (x + y) / 2));
        else return _setter(node->data,
                            query(p, node->r_child(), (x + y) / 2, y));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    ImplicitSegupdate<ll> eaten_x(n + 1, [](ll a, ll b) { return max(a, b); });
    ImplicitSegupdate<ll> eaten_y(n + 1, [](ll a, ll b) { return max(a, b); });
    set<pll> used;
    while (q--) {
        ll x, y;
        char d;
        cin >> x >> y >> d;
        if (used.find({x, y}) != used.end()) {
            cout << 0 << endl;
        } else if (d == 'L') {
            ll end = eaten_x.query(y);
            cout << x - end << endl;
            eaten_y.modify(end + 1, x + 1, y);
            used.emplace(x, y);
        } else if (d == 'U') {
            ll end = eaten_y.query(x);
            cout << y - end << endl;
            eaten_x.modify(end + 1, y + 1, x);
            used.emplace(x, y);
        }
    }
}