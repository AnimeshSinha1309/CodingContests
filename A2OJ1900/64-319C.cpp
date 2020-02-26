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

class LineContainer {
   private:
    struct Line {
        mutable long long slope, constt, p;
        bool operator<(const Line &o) const {
            return slope < o.slope;
        }
        bool operator<(long long x) const {
            return p < x;
        }
    };

    multiset<Line, less<>> lines;
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    bool __is_max_query = false;
    const long long inf = LLONG_MAX;
    long long __div(long long a, long long b) {  // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool __intersect(multiset<Line>::iterator x, multiset<Line>::iterator y) {
        if (y == lines.end()) {
            x->p = inf;
            return false;
        }
        if (x->slope == y->slope)
            x->p = x->constt > y->constt ? inf : -inf;
        else
            x->p = __div(y->constt - x->constt, x->slope - y->slope);
        return x->p >= y->p;
    }

   public:
    LineContainer(bool is_max = false) {
        this->__is_max_query = is_max;
    }
    void add(long long slope, long long constt) {
        if (!__is_max_query) {
            slope = -slope;
            constt = -constt;
        }
        auto z = lines.insert({slope, constt, 0}), y = z++, x = y;
        while (__intersect(y, z))
            z = lines.erase(z);
        if (x != lines.begin() && __intersect(--x, y))
            __intersect(x, y = lines.erase(y));
        while ((y = x) != lines.begin() && (--x)->p >= y->p)
            __intersect(x, lines.erase(y));
    }
    long long query(long long x) {
        assert(!lines.empty());
        auto l = *lines.lower_bound(x);
        return (l.slope * x + l.constt) * (__is_max_query ? 1 : -1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Take the inputs and initialize Line-Container
    LineContainer lc(false);
    ll n;
    cin >> n;
    vpl trees(n);
    for (int i = 0; i < n; i++)
        cin >> trees[i].first;
    for (int i = 0; i < n; i++)
        cin >> trees[i].second;
    // Loop over and perform DP Convex Hull Trick
    lc.add(trees[0].second, 0);
    for (int i = 1; i < n - 1; i++) {
        ll cost = lc.query(trees[i].first);
        lc.add(trees[i].second, cost);
    }
    ll ans = lc.query(trees[n - 1].first);
    cout << ans << endl;
}