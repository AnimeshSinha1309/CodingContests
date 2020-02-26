#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Constraint { unsigned int l, r, q; };

#ifndef CODE_SEGUPD_H
#define CODE_SEGUPD_H

#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

template<class Type>
class SegmentUpdate {
protected:
    vector<Type> data; unsigned long size;
    inline unsigned long parent(unsigned long i) { return i >> 1; }
    inline unsigned long lChild(unsigned long i) { return i << 1; }
    inline unsigned long rChild(unsigned long i) { return i << 1 | 1; }
    inline unsigned long sibling(unsigned long i) { return i ^ 1; }
    inline unsigned long element(unsigned long i) { return i + size; }
    inline bool isRoot(unsigned long i) { return i == 1; }
    inline bool islChild(unsigned long i) { return (i & 1) == 0; }
    inline bool isrChild(unsigned long i) { return (i & 1) != 0; }
    function<Type (Type, Type)> operation;
    Type defaultValue;
public:
    explicit SegmentUpdate(const vector<Type> &list, function<Type (Type, Type)> segOperation, Type defaultTo) {
        size = (1ul << (long)ceil(log2(list.size())));
        data = vector<Type>(size * 2, defaultTo);
        defaultValue = defaultTo; operation = segOperation;
        for (unsigned long i = 0; i < list.size(); i++) data[i + size] = list[i];
        for (unsigned long i = size - 1; i > 0; --i) data[i] = operation(data[lChild(i)], data[rChild(i)]);
    }
    void modify(unsigned long l, unsigned long r, Type value) {
        for (l = element(l), r = element(r); l < r; l = parent(l), r = parent(r)) {
            if (isrChild(l)) { data[l] = operation(data[l], value); l++; }
            if (isrChild(r)) { --r; data[r] = operation(data[r], value); }
        }
    }
    Type query(unsigned long position) {
        Type accumulator = defaultValue;
        for (position = element(position); ; position = parent(position)) {
            accumulator = operation(accumulator, data[position]);
            if (isRoot(position)) break;
        } return accumulator;
    }
};

#endif //CODE_SEGUPD_H

#ifndef CODE_SEGTREE_H
#define CODE_SEGTREE_H

#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

template<class Type>
class SegmentTree {
protected:
    vector<Type> data; unsigned long size;
    inline unsigned long parent(unsigned long i) { return i >> 1; }
    inline unsigned long lChild(unsigned long i) { return i << 1; }
    inline unsigned long rChild(unsigned long i) { return i << 1 | 1; }
    inline unsigned long sibling(unsigned long i) { return i ^ 1; }
    inline unsigned long element(unsigned long i) { return i + size; }
    inline bool isRoot(unsigned long i) { return i == 1; }
    inline bool islChild(unsigned long i) { return (i & 1) == 0; }
    inline bool isrChild(unsigned long i) { return (i & 1) != 0; }
    function<Type (Type, Type)> operation;
    Type defaultValue;
public:
    explicit SegmentTree(const vector<Type> &list, function<Type (Type, Type)> segOperation, Type defaultTo) {
        size = (1ul << (long)ceil(log2(list.size())));
        data = vector<Type>(size * 2, defaultTo);
        defaultValue = defaultTo; operation = segOperation;
        for (unsigned long i = 0; i < list.size(); i++) data[i + size] = list[i];
        for (unsigned long i = size - 1; i > 0; --i) data[i] = operation(data[lChild(i)], data[rChild(i)]);
    }
    void modify(unsigned long position, Type value) {
        data[element(position)] = value;
        for (position = element(position); !isRoot(position); position = parent(position)) {
            if (islChild(position)) data[parent(position)] = operation(data[position], data[sibling(position)]);
            if (isrChild(position)) data[parent(position)] = operation(data[sibling(position)], data[position]);
        }
    }
    Type query(unsigned long l, unsigned long r) {
        Type lAccumulator = defaultValue, rAccumulator = defaultValue;
        for (l = element(l), r = element(r); l < r; l = parent(l), r = parent(r)) {
            if (isrChild(l)) { lAccumulator = operation(lAccumulator, data[l++]); }
            if (isrChild(r)) { rAccumulator = operation(data[--r], rAccumulator); }
        } return operation(lAccumulator, rAccumulator);
    }
};

#endif //CODE_HEAP_H

int main() {
    unsigned int n, m; cin >> n >> m; bool correct = true;
    vector<Constraint> query(m); for (auto &item : query) cin >> item.l >> item.r >> item.q;
    // Segment Updates to construct the array
    vector<unsigned int> list(n, 0);
    SegmentUpdate<unsigned int> seg(list, [](unsigned int a, unsigned int b) { return a | b; }, 0);
    for (const auto &q : query) seg.modify(q.l-1, q.r, q.q);
    // Segment Queries to test the array
    vector<unsigned int> result(n, 0); for (unsigned long i = 0; i < n; i++) result[i] = seg.query(i);
    SegmentTree<unsigned int> str(result, [](unsigned int a, unsigned int b) { return a & b; }, 0xFFFFFFFF);
    for (const auto &q : query) if (str.query(q.l-1, q.r) != q.q) { correct = false; break; }
    cout << (correct ? "YES" : "NO") << endl;
    if (correct) { for (const auto &item : result) cout << item << " "; cout << endl; }
}