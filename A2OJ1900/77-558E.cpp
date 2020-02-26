// TODO: Solved using Editorial, Try Again

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#ifndef CODE_LAZYSEG_H
#define CODE_LAZYSEG_H

#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

#define SETTER(a, b) (a)
#define OPERATION(a, b) (a+b)
#define SCALE_RANGE(a, range) (a * (range.second - range.first))
#define SCALE_CHILD(a) (a / 2)
#define DEFAULT 0

template<class Type>
class LazySegtree {
protected:
    vector<Type> data, lazy; vector<bool> wait; unsigned long size;
    inline unsigned long lChild(unsigned long i) { return i << 1; }
    inline unsigned long rChild(unsigned long i) { return i << 1 | 1; }
    inline unsigned long element(unsigned long i) { return i + size; }
    inline bool isLeaf(unsigned long i) { return i >= size; }
    inline Type eval(unsigned long i) { return wait[i] ? SETTER(lazy[i], data[i]) : data[i]; }

    inline bool partialCover(pair<long,long> cover, pair<long,long> interval) {
        return cover.second > interval.first && cover.first < interval.second;
    }
    inline bool totalCover(pair<long,long> cover, pair<long,long> interval) {
        return cover.second >= interval.second && cover.first <= interval.first;
    }
    void build(unsigned long pos = 1) {
        if (isLeaf(pos)) return; build(lChild(pos)); build(rChild(pos));
        data[pos] = OPERATION(data[lChild(pos)], data[rChild(pos)]);
    }
    inline void lazyprop(unsigned long pos) {
        if (!wait[pos]) return;
        if (isLeaf(pos)) {
            data[pos] = eval(pos); wait[pos] = false;
            lazy[pos] = DEFAULT; return;
        }
        lazy[lChild(pos)] = SETTER(SCALE_CHILD(lazy[pos]), lazy[lChild(pos)]);
        lazy[rChild(pos)] = SETTER(SCALE_CHILD(lazy[pos]), lazy[rChild(pos)]);
        wait[lChild(pos)] = true; wait[rChild(pos)] = true; wait[pos] = false;
        lazy[pos] = DEFAULT;
        data[pos] = OPERATION(eval(lChild(pos)), eval(rChild(pos)));
    }
    Type query(pair<long,long> qrange, pair<long,long> current, unsigned long pos) {
        if (totalCover(qrange, current)) return eval(pos);
        else if (partialCover(qrange, current)) {
            lazyprop(pos);
            return OPERATION(query(qrange, {current.first, (current.first+current.second)/2}, lChild(pos)),
                             query(qrange, {(current.first+current.second)/2, current.second}, rChild(pos)));
        } else return DEFAULT;
    }
    void modify(pair<long,long> qrange, pair<long,long> current, unsigned long pos, Type value) {
        if (totalCover(qrange, current)) {
            lazyprop(pos);
            if (isLeaf(pos)) { data[pos] = SETTER(value, data[pos]); return; }
            lazy[pos] = SCALE_RANGE(value, current);
            wait[pos] = true;
        } else if (partialCover(qrange, current)) {
            lazyprop(pos);
            modify(qrange, {current.first, (current.first+current.second)/2}, lChild(pos), value);
            modify(qrange, {(current.first+current.second)/2, current.second}, rChild(pos), value);
            data[pos] = OPERATION(eval(lChild(pos)), eval(rChild(pos)));
        } else return;
    }
public:
    explicit LazySegtree(const vector<Type> &list) {
        size = (1ul << (long)ceil(log2(list.size())));
        data = vector<Type>(size * 2, DEFAULT);
        lazy = vector<Type>(size * 2, DEFAULT);
        wait = vector<bool>(size * 2, false);
        for (unsigned int i = 0; i < list.size(); i++) data[element(i)] = list[i]; build();
    }
    void modify(unsigned long l, unsigned long r, Type value) {
        modify({l, r}, {0, size}, 1, value);
    }
    Type query(unsigned long l, unsigned long r) {
        return query({l, r}, {0, size}, 1);
    }
};

#endif //CODE_LAZYSEG_H


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    unsigned int n, q; cin >> n >> q; string st; cin >> st;
    vector<vector<int>> count(26, vector<int>(n, 0)); for (int i = 0; i < st.size(); i++) count[st[i]-'a'][i]++;
    vector<LazySegtree<int>> tree; tree.reserve(26);
    for (int i = 0; i < 26; i++) tree.emplace_back(count[i]);
    while (q--) {
        unsigned int l, r, k; cin >> l >> r >> k; l--; vector<int> numbers(26, 0);
        for (int i = 0; i < 26; i++) numbers[i] = tree[i].query(l, r);
        for (int i = 0; i < 26; i++) tree[i].modify(l, r, 0);
        if (k == 1) {
            for (unsigned int i = 0, shift = l; i < 26; shift += numbers[i++])
                tree[i].modify(shift, shift + numbers[i], 1);
        } else {
            for (unsigned int i = 25, shift = l; i >= 0 && i < 30; shift += numbers[i--])
                tree[i].modify(shift, shift + numbers[i], 1);
        }
    }
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < 26; j++) {
            if (tree[j].query(i, i+1) == 1) { cout << (char)('a' + j); break; }
        }
    } cout << endl;
}