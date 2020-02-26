#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
using namespace std;

template<class Type>
class SegmentTree {
protected:
    vector<Type> data; unsigned long size;
    inline unsigned long parent(unsigned long i) { return i >> 1; }
    inline unsigned long element(unsigned long i) { return i + size; }
    inline bool isRoot(unsigned long i) { return i == 1; }
    inline bool isrChild(unsigned long i) { return (i & 1) != 0; }
public:
    explicit SegmentTree(const vector<Type> &list) {
        size = (1ul << (long)ceil(log2(list.size())));
        data = vector<Type>(size * 2, 0);
        for (unsigned long i = 0; i < list.size(); i++) data[i + size] = list[i];
        for (unsigned long i = size - 1; i > 0; --i) data[i] = INT32_MAX;
    }
    void modify(unsigned long l, unsigned long r, Type value) {
        for (l = element(l), r = element(r); l < r; l = parent(l), r = parent(r)) {
            if (isrChild(l)) data[l++] = value;
            if (isrChild(r)) data[--r] = value;
        }
    }
    Type query(unsigned long position) {
        Type accumulator = INT32_MAX;
        for (position = element(position); !isRoot(position); position = parent(position)) {
            accumulator = min(accumulator, data[position]);
        } return accumulator;
    }
};

int main() {
    struct Fight { unsigned long l, r, winner; };
    unsigned int n, m; cin >> n >> m;
    vector<Fight> list(m); for (auto &item : list) cin >> item.l >> item.r >> item.winner;
    vector<long> defeat(n); for (int i = 0; i < n; i++) defeat[i] = INT32_MAX;
    SegmentTree<long> seg(defeat);
    for (int i = m-1; i >= 0; i--) {
        seg.modify(list[i].l - 1, list[i].winner - 1, i);
        seg.modify(list[i].winner, list[i].r, i);
    }
    for (unsigned long i = 0; i < n; i++) {
        long round = seg.query(i);
        cout << (round == INT32_MAX ? 0 : list[round].winner) << " ";
    }
}