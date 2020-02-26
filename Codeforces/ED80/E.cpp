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

class SegmentTree {
   protected:
    vll data;
    unsigned long size;
    inline unsigned long parent(unsigned long i) {
        return i >> 1;
    }
    inline unsigned long lChild(unsigned long i) {
        return i << 1;
    }
    inline unsigned long rChild(unsigned long i) {
        return i << 1 | 1;
    }
    inline unsigned long sibling(unsigned long i) {
        return i ^ 1;
    }
    inline unsigned long element(unsigned long i) {
        return i + size;
    }
    inline bool isRoot(unsigned long i) {
        return i == 1;
    }
    inline bool islChild(unsigned long i) {
        return (i & 1) == 0;
    }
    inline bool isrChild(unsigned long i) {
        return (i & 1) != 0;
    }

    ll size = 0;

   public:
    explicit SegmentTree(int n) {
        for (size = 1; size < 2 * n; size *= 2)
            ;
        data = vector<ll>(size * 2, 0);
    }
    void modify(ll pos, ll value) {
        data[element(pos)] = value > 0;
        for (data[pos = element(pos)]; !isRoot(pos); pos = parent(pos)) {
            if (islChild(pos))
                data[parent(pos)] = data[pos] + data[sibling(pos)];
            if (isrChild(pos))
                data[parent(pos)] = data[sibling(pos)] + data[pos];
        }
    }
    ll query(ll l, ll r) {
        ll l_acc = 0, r_acc = 0;
        for (l = element(l), r = element(r); l < r;
             l = parent(l), r = parent(r)) {
            if (isrChild(l))
                l_acc = l_acc + data[l++];
            if (isrChild(r))
                r_acc = data[--r] + r_acc;
        }
        return l_acc + r_acc;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vll a(n);
    cin >> a;
    vll minima(n), maxima(n);
    mll got_message(n);
    for (int i = 0; i < n; i++) {
        got_message[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        minima[i] = got_message[i].empty() ? i : 1;
        maxima[i] = i;
    }
    SegmentTree seg(n);
    vll last_touched(n, -1);
    for (int i = 0; i < n; i++) {
    }
}