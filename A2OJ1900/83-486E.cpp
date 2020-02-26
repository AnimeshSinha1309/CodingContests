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

pll combine(pll a, pll b) {
    return (a.first == b.first) ? pll(a.first, (a.second + b.second) % MOD)
                                : max(a, b);
}

template <class Type>
class SegmentTree {
#define SETTER(a, b) (combine(a, b))
   public:
    vector<Type> data;
    unsigned long size;
    function<Type(Type, Type)> operation;
    Type default_value;

    SegmentTree(const vector<Type> &list, function<Type(Type, Type)> op,
                Type default_to) {
        size = (1ul << (long)ceil(log2(list.size())));
        data = vector<Type>(size * 2, default_to);
        default_value = default_to;
        operation = op;
        for (int i = 0; i < list.size(); i++)
            data[i + size] = list[i];
        for (int i = size - 1; i > 0; --i)
            data[i] = operation(data[i << 1], data[i << 1 | 1]);
    }
    void modify(int pos, Type value) {
        data[pos + size] = SETTER(data[pos + size], value);
        for (pos = pos + size; !(pos == 1); pos >>= 1) {
            if ((pos & 1) == 0)
                data[pos >> 1] = operation(data[pos], data[pos ^ 1]);
            if ((pos & 1) != 0)
                data[pos >> 1] = operation(data[pos ^ 1], data[pos]);
        }
    }
    Type query(int l, int r) {
        Type l_acc = default_value, r_acc = default_value;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if ((l & 1) != 0)
                l_acc = operation(l_acc, data[l++]);
            if ((r & 1) != 0)
                r_acc = operation(data[--r], r_acc);
        }
        return operation(l_acc, r_acc);
    }
};

#define LIMIT 100001

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // Compute the LIS in (start, x) and (x, end)
    SegmentTree<pll> seg1(vpl(LIMIT, {0ll, 0ll}), combine, {0ll, 0ll});
    SegmentTree<pll> seg2(vpl(LIMIT, {0ll, 0ll}), combine, {0ll, 0ll});
    pll lis_full;
    vpl data_start(n), data_end(n);
    for (int i = 0; i < n; i++) {
        pll res = seg1.query(0, a[i]);
        if (res.first == 0)
            res = {0, 1};
        seg1.modify(a[i], {res.first + 1, res.second});
        data_start[i] = {res.first + 1, res.second};
        lis_full = combine(lis_full, {res.first + 1, res.second});
    }
    for (int i = n - 1; i >= 0; i--) {
        pll res = seg2.query(a[i] + 1, LIMIT);
        if (res.first == 0)
            res = {0, 1};
        seg2.modify(a[i], {res.first + 1, res.second});
        data_end[i] = {res.first + 1, res.second};
    }
    // Assign the Type of elements
    for (int i = 0; i < n; i++) {
        ll max_length =
            (data_start[i].first + data_end[i].first - 1 + MOD) % MOD;
        ll max_count = (data_start[i].second * data_end[i].second) % MOD;
        if (max_length == lis_full.first && max_count == lis_full.second)
            cout << 3;
        else if (max_length == lis_full.first)
            cout << 2;
        else
            cout << 1;
    }
    cout << endl;
}