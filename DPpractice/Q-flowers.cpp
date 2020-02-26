#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long long, long long> pll;
#define minimize(var, val) (var = min((val), var))

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
        data[element(position)] = value;
        for (position = element(position); !isRoot(position);
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

vector<long long> get_sorted_index(vector<long long> arr) {
    vector<pair<long long, long long>> sortable(arr.size());
    for (int i = 0; i < arr.size(); i++)
        sortable[i] = {arr[i], i};
    sort(sortable.begin(), sortable.end());
    vector<long long> index(arr.size());
    for (int i = 0; i < arr.size(); i++)
        index[sortable[i].second] = i;
    return index;
}

int main() {
    ll n;
    cin >> n;
    vll h(n), a(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vll h_index = get_sorted_index(h);

    SegmentTree<ll> seg(vll(n, 0), [](ll a, ll b) { return max(a, b); }, 0);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll res = seg.query(0, h_index[i]) + a[i];
        seg.modify(h_index[i], res);
        ans = max(ans, res);
    }
    cout << ans << endl;
}