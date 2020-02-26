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

template <class Type>
class SegmentTree {
   protected:
    vector<Type> data;
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
    function<Type(Type, Type)> operation;
    Type defaultValue;

   public:
    explicit SegmentTree(const vector<Type> &list,
                         function<Type(Type, Type)> segOperation,
                         Type defaultTo) {
        size = (1ul << (long)ceil(log2(list.size())));
        data = vector<Type>(size * 2, defaultTo);
        defaultValue = defaultTo;
        operation = segOperation;
        for (unsigned long i = 0; i < list.size(); i++)
            data[i + size] = list[i];
        for (unsigned long i = size - 1; i > 0; --i)
            data[i] = operation(data[lChild(i)], data[rChild(i)]);
    }
    void modify(unsigned long position, Type value) {
        data[element(position)] += value;
        for (data[position = element(position)]; !isRoot(position);
             position = parent(position)) {
            if (islChild(position))
                data[parent(position)] =
                    operation(data[position], data[sibling(position)]);
            if (isrChild(position))
                data[parent(position)] =
                    operation(data[sibling(position)], data[position]);
        }
    }
    Type query(unsigned long l, unsigned long r) {
        Type lAccumulator = defaultValue, rAccumulator = defaultValue;
        for (l = element(l), r = element(r); l < r;
             l = parent(l), r = parent(r)) {
            if (isrChild(l)) {
                lAccumulator = operation(lAccumulator, data[l++]);
            }
            if (isrChild(r)) {
                rAccumulator = operation(data[--r], rAccumulator);
            }
        }
        return operation(lAccumulator, rAccumulator);
    }
};

vll rankify(const vll &arr) {
    int n = arr.size();
    vpl s(n);
    for (int i = 0; i < n; i++)
        s[i] = {arr[i], i};
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++)
        s[i].first = i;
    vll res(n);
    for (int i = 0; i < n; i++)
        res[s[i].second] = i;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    a = rankify(a);
    set<ll> seen;
    SegmentTree<ll> l1(vll(n + 1, 0), [](ll a, ll b) { return a + b; }, 0ll);
    SegmentTree<ll> l2(vll(n + 1, 0), [](ll a, ll b) { return a + b; }, 0ll);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll count1 = l1.query(a[i], n + 1);
        ll count2 = l2.query(a[i], n + 1);
        l1.modify(a[i], 1);
        l2.modify(a[i], count1);
        ans += count2;
    }
    cout << ans << endl;
}