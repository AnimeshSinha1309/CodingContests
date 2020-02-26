#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long double, long double> pld;
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

class Tree {
   public:
    struct Node {
        vector<Node *> adjacent;
        Node *parent = nullptr;
        long long start_time = 0, end_time = 0, subtree_size = 1;
        unsigned long depth = 0, height = 0;
        unsigned long index = INT32_MAX;
    };

    vector<Node> list;
    Node *root = nullptr;
    vector<vector<Node *>> __anc;

    Tree(int n = 1e5) {
        list.resize(n);
        this->root = &list[0];
        for (int i = 0; i < n; i++)
            list[i].index = i;
    }
    void add_edge(int x, int y) {
        list[x].adjacent.push_back(&list[y]);
        list[y].adjacent.push_back(&list[x]);
    }

    Node *lca(Node *a, Node *b) {
        if (b->depth > a->depth)
            swap(a, b);
        for (int ptr = __anc[0].size() - 1; a->depth > b->depth && ptr >= 0;
             ptr--) {
            if (__anc[a->index][ptr] != nullptr &&
                __anc[a->index][ptr]->depth >= b->depth)
                a = __anc[a->index][ptr];
        }
        if (a == b)
            return a;
        for (long step = __anc[0].size() - 1; step >= 0; step--) {
            if (__anc[a->index][step] != __anc[b->index][step])
                a = __anc[a->index][step], b = __anc[b->index][step];
        }
        return a->parent;
    }
    Node *ancestor(Node *a, int degree) {
        ll target_depth = a->depth - degree;
        for (int ptr = __anc[0].size() - 1; a->depth > target_depth && ptr >= 0;
             ptr--) {
            if (__anc[a->index][ptr] != nullptr &&
                __anc[a->index][ptr]->depth >= target_depth)
                a = __anc[a->index][ptr];
        }
        return a;
    }
    int __build(Node *root = nullptr, int time = 0) {
        if (root == nullptr)
            root = this->root;
        root->start_time = time;
        for (auto child : root->adjacent) {
            if (child == root->parent)
                continue;
            child->parent = root;
            child->depth = root->depth + 1;
            time = __build(child, time + 1);
            root->height = max(root->height, child->height + 1);
            root->subtree_size += child->subtree_size;
        }
        root->end_time = time;
        return time;
    }
    void __build_lca_matrix() {
        int n = list.size();
        __anc = *new vector<vector<Node *>>(
            n, vector<Node *>(log2(n) + 1, nullptr));
        for (int i = 0; i < list.size(); i++)
            __anc[i][0] = list[i].parent;
        for (int level = 1; level < __anc[0].size(); level++)
            for (int i = 0; i < list.size(); i++) {
                if (__anc[i][level - 1] == nullptr)
                    continue;
                __anc[i][level] = __anc[__anc[i][level - 1]->index][level - 1];
            }
    }
};

class Point {
   public:
    typedef long double coord_t;
    coord_t x, y;

    Point(coord_t coord_x = 0, coord_t coord_y = 0) {
        this->x = coord_x;
        this->y = coord_y;
    }
    Point(pair<coord_t, coord_t> coord) {
        this->x = coord.first;
        this->y = coord.second;
    }
    static coord_t area(const Point &a, const Point &b, const Point &c) {
        // Area function: area < 0 = clockwise, area > 0 counterclockwise
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    };
    static coord_t area(const vector<Point> &polygon) {
        int n = polygon.size();
        coord_t ans = 0;
        for (int i = 0; i < n; i++) {
            ans += polygon[i].x * polygon[(i + 1) % n].y -
                   polygon[i].y * polygon[(i + 1) % n].x;
        }
    }
    friend bool operator<(const Point &a, const Point &b) {
        return (a.x != b.x) ? a.x < b.x : a.y < b.y;
    }
    friend bool operator==(const Point &a, const Point &b) {
        return (a.x == b.x) && (a.y == b.y);
    }
    friend istream &operator>>(istream &in, Point &p) {
        in >> p.x >> p.y;
        return in;
    }
    friend ostream &operator<<(ostream &out, Point &p) {
        out << p.x << " " << p.y;
        return out;
    }
    static coord_t sq_dist(const Point &a, const Point &b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }

    static vector<pair<Point, int>> convex_hull(vector<Point> &arr) {
        vector<pair<Point, int>> a(arr.size());
        for (int i = 0; i < arr.size(); i++)
            a[i].first = arr[i], a[i].second = i;
        if (a.size() <= 3)
            return a;
        int n = a.size(), k = 0;
        sort(a.begin(), a.end());
        vector<pair<Point, int>> result(2 * n);
        // Construction of Lower Hull
        for (int i = 0; i < n; ++i) {
            while (k >= 2 && area(result[k - 2].first, result[k - 1].first,
                                  a[i].first) < 0)
                k--;
            result[k++] = a[i];
        }
        // Construction of Upper Hull
        for (int i = n - 1, t = k + 1; i >= 0; --i) {
            while (k >= t && area(result[k - 2].first, result[k - 1].first,
                                  a[i - 1].first) < 0)
                k--;
            result[k++] = a[i - 1];
        }
        result.resize(k - 1);
        return result;
    }
};

vector<int> convex_parent(vector<Point> &arr) {
    vector<int> parent(arr.size());
    for (int i = arr.size() - 1, t = k + 1; i >= 0; --i) {
        while (k >= t && area(result[k - 2].first, result[k - 1].first,
                              a[i - 1].first) < 0)
            k--;
        result[k++] = a[i - 1];
    }
}

int main() {
    // Taking all the Inputs
    unsigned int n;
    cin >> n;
    vector<Point> hills(n);
    cin >> hills;
    // Preparing the Convex Hull Tree
    Tree tree(n);
    vll next(n, n - 1);
    auto hull = Point::convex_hull(hills);
    for (auto el : hull)
        next[el.second] = el.second;
    for (int i = n - 2; i >= 0; i--)
        next[i] = min(next[i], next[i + 1]);
    for (int i = 0; i < n - 1; i++) {
        tree.add_edge(i, next[i]);
    }
    tree.__build(&tree.list[n - 1]);
    tree.__build_lca_matrix();
    // Processing the Queries
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        unsigned long join =
            tree.lca(&tree.list[x - 1], &tree.list[y - 1])->index + 1;
        cout << join << " ";
    }
}