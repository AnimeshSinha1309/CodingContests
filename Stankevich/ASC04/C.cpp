#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const long long MOD = 1e9 + 7;
const double EPS = 1e-9;

template <typename Type>
struct Point {
    Type x, y;
    Point(Type x = 0, Type y = 0) : x(x), y(y) {
    }
    bool operator<(const Point &p) const {
        return abs(x - p.x) > EPS ? x < p.x : y < p.y;
    }
    bool operator==(const Point &p) const {
        return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
    }
    Point rotate(Type a) const {
        Type cs = cos(a), sn = sin(a);
        return Point(x * cs - y * sn, x * sn + y * cs);
    }
    Type cross(const Point &p) const {
        return x * p.y - y * p.x;
    }
    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
};

struct Line {
    ll a, b, c;
    Line() {
    }
    Line(const Point<ll> &x, const Point<ll> &y) {
        a = x.y - y.y;
        b = y.x - x.x;
        c = -(a * x.x + b * x.y);
    }
    bool intersects(const Line &other_line) const {
        return a * other_line.b != b * other_line.a;
    }
    Point<ld> cut(const Line &other_line) const {
        double d = 1. * a * other_line.b - 1. * b * other_line.a;
        double dx = 1. * b * other_line.c - 1. * c * other_line.b;
        double dy = 1. * c * other_line.a - 1. * a * other_line.c;
        return Point<ld>(dx / d, dy / d);
    }
};

const int N = 80 + 4, P = N * (N - 1) / 2, INF = 1e9;

class Graph {
   public:
    vector<Point<ld>> intersection_points;
    vector<vector<Point<ld>>> intersection_points_on_lines;

    vector<vector<int>> adjacency;
    int n_nodes, n_intersections, n_regions;
    vector<int> previous, in_degree, out_degree;
    vector<double> regions;
    vector<Line> lines_input;

    Graph(int n, vector<Line> &lines) {
        previous.resize(P, -1);
        in_degree.resize(P);
        out_degree.resize(P);
        adjacency.resize(P);
        n_nodes = n;
        lines_input = lines;
        // Compute all the points of intersection
        intersection_points_on_lines.resize(n);
        intersection_points.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (lines_input[i].intersects(lines_input[j])) {
                    Point<ld> p = lines_input[i].cut(lines_input[j]);
                    if (abs(p.x) <= INF && abs(p.y) <= INF) {
                        p = p.rotate(0.01);
                        intersection_points_on_lines[i].push_back(p);
                        intersection_points_on_lines[j].push_back(p);
                        intersection_points.push_back(p);
                    }
                }
            }
        }
        // Sort and Get unique points of intersection
        sort(intersection_points.begin(), intersection_points.end());
        intersection_points.erase(
            unique(intersection_points.begin(), intersection_points.end()),
            intersection_points.end());
        n_intersections = intersection_points.size();
    }

    void dfs(int u, double area) {
        if (previous[u] != -1) {
            // A region is to be made, run the DFS and store it's area
            for (int v = u; previous[v] != -1; v = previous[v])
                area += intersection_points[v].cross(
                    intersection_points[previous[v]]);
            area = abs(area) / 2;
            if (area > 1e-8)
                regions.push_back(area);
        } else {
            // If this is the same regions keep setting previous and adding
            // areas
            for (auto adjacent : this->adjacency[u]) {
                int v = adjacent;
                dfs(v, area + intersection_points[u].cross(
                                  intersection_points[v]));
                previous[v] = u;
                area = 0;
            }
        }
    }

    void build_adjacency() {
        for (int u = 0; u < n_intersections; ++u)
            adjacency[u].clear();
        int n_edges = 0;
        for (auto &points_on_line : intersection_points_on_lines) {
            // Sort and Get unique
            sort(points_on_line.begin(), points_on_line.end());
            points_on_line.erase(
                unique(points_on_line.begin(), points_on_line.end()),
                points_on_line.end());
            // Make the adjacency between all pairs of points on the same line
            for (int j = 0; j < (int)points_on_line.size() - 1; ++j) {
                int u =
                    lower_bound(intersection_points.begin(),
                                intersection_points.end(), points_on_line[j]) -
                    intersection_points.begin();
                int v = lower_bound(intersection_points.begin(),
                                    intersection_points.end(),
                                    points_on_line[j + 1]) -
                        intersection_points.begin();
                this->adjacency[u].push_back(v);
                ++n_edges;
            }
        }
        // Store the number of regions formed
        n_regions = intersection_points.empty()
                        ? 0
                        : 1 + n_edges - intersection_points.size();
    }

    void sort_neighbors() {
        for (int u = 0; u < n_intersections; ++u) {
            vector<pair<Point<ld>, int>> ys;
            for (int adjacent : adjacency[u])
                ys.push_back(make_pair(
                    intersection_points[adjacent] - intersection_points[u],
                    adjacent));
            sort(ys.begin(), ys.end(), pair_compare);
            for (unsigned i = 0; i < adjacency[u].size(); ++i)
                adjacency[u][i] = ys[i].second;
        }
    }

    static bool pair_compare(const pair<Point<ld>, int> &x,
                             const pair<Point<ld>, int> &y) {
        return x.first.cross(y.first) > 0;
    }
};

int main() {
    freopen("areas.in", "r", stdin);
    freopen("areas.out", "w", stdout);
    // Take the inputs and append extra boundary lines
    int n;
    cin >> n;
    vector<Line> lines(n);
    for (int i = 0; i < n; ++i) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        lines[i] = Line(Point<ll>(x, y), Point<ll>(u, v));
    }
    // Get the regions count
    Graph h(n, lines);
    h.build_adjacency();
    int n_regions = h.n_regions;
    // Put the extras
    lines.emplace_back(Point<ll>(-INF, -INF), Point<ll>(INF, -INF));
    lines.emplace_back(Point<ll>(INF, -INF), Point<ll>(INF, INF));
    lines.emplace_back(Point<ll>(INF, INF), Point<ll>(-INF, INF));
    lines.emplace_back(Point<ll>(-INF, INF), Point<ll>(-INF, -INF));
    n += 4;
    // Make the graph, sort the adjacency lists, and do a DFS
    Graph g(n, lines);
    g.build_adjacency();
    g.sort_neighbors();
    g.dfs(0, 0);
    // Output the answers in sorted order
    sort(g.regions.begin(), g.regions.end());
    g.regions.resize(n_regions);
    cout << n_regions << fixed << setprecision(6) << endl;
    for (int i = 0; i < n_regions; ++i)
        cout << g.regions.at(i) << endl;
    return 0;
}