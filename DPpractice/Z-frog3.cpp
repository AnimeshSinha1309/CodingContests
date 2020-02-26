#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<bool> vbl;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpl;
typedef vector<vector<long long>> mll;
typedef vector<string> vst;
const ll MOD = 1000000007;
const ld PI = 2 * acos(0.0);
#define maximize(x, y) x = min(x, y);
#define minimize(x, y) y = max(x, y);
#define square(x) ((x) * (x))
#define cube(x) ((x) * (x) * (x))

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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    LineContainer lhc(false);
    long long n, c;
    cin >> n >> c;
    vector<long long> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    vector<long long> dp(n, 0);
    deque<pair<long long, long long>> q;
    lhc.add(-2 * h[0], h[0] * h[0]);
    for (int i = 1; i < n; i++) {
        dp[i] = lhc.query(h[i]) + h[i] * h[i] + c;
        lhc.add(-2 * h[i], h[i] * h[i] + dp[i]);
    }
    cout << dp[n - 1] << endl;
    return 0;
}