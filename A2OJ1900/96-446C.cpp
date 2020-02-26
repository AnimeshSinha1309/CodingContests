#include <stdio.h>

#define MAX_N 300002
int fib_prefix[MAX_N];
const int MOD = 1e9 + 9;
int a[MAX_N];

int sz;
int tree[4 * MAX_N];
int lazy1[2 * MAX_N];
int lazy2[2 * MAX_N];

void split(int node) {
    if (2 * node < sz && lazy2[2 * node] != 0)
        split(2 * node);
    if (2 * node + 1 < sz && lazy2[2 * node + 1] != 0)
        split(2 * node + 1);
    int mid = (lazy1[node] + lazy2[node]) / 2;
    tree[2 * node] = ((tree[2 * node] + fib_prefix[mid]) % MOD -
                      fib_prefix[lazy1[node]] + MOD) %
                     MOD;
    tree[2 * node + 1] = ((tree[2 * node + 1] + fib_prefix[lazy2[node]]) % MOD -
                          fib_prefix[mid] + MOD) %
                         MOD;
    lazy1[2 * node] = lazy1[node];
    lazy2[2 * node] = mid;
    lazy1[2 * node + 1] = mid;
    lazy2[2 * node + 1] = lazy2[node];
    lazy1[node] = 0;
    lazy2[node] = 0;
}
void merge(int node) {
    tree[node] = (tree[2 * node] + tree[2 * node + 1]) % MOD;
}

void init(int n) {
    for (sz = 1; sz < n; sz <<= 1)
        ;
}

void modify(int l, int r, int node, int x, int y) {
    if (r <= x || l >= y)
        return;
    if (l <= x && y <= r) {
        if (node < sz && lazy2[node] != 0)
            split(node);
        lazy1[node] = x - l;
        lazy2[node] = y - l;
        tree[node] =
            ((tree[node] + fib_prefix[y - l]) % MOD - fib_prefix[x - l] + MOD) %
            MOD;
        return;
    }
    if (node < sz && lazy2[node] != 0)
        split(node);
    modify(l, r, 2 * node, x, (x + y) / 2);
    modify(l, r, 2 * node + 1, (x + y) / 2, y);
    merge(node);
}

int query(int l, int r, int node, int x, int y) {
    if (y == -1)
        y = sz;
    if (r <= x || l >= y)
        return 0;
    if (l <= x && y <= r) {
        return tree[node];
    }
    if (node < sz && lazy2[node] != 0)
        split(node);
    int lres = query(l, r, 2 * node, x, (x + y) / 2);
    int rres = query(l, r, 2 * node + 1, (x + y) / 2, y);
    merge(node);
    return (lres + rres) % MOD;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    // Compute the Fibonacci Numbers and Prefix Sum
    fib_prefix[0] = 0;
    fib_prefix[1] = 1;
    for (int i = 2; i <= n; i++)
        fib_prefix[i] = (fib_prefix[i - 1] + fib_prefix[i - 2]) % MOD;
    for (int i = 1; i <= n; i++)
        fib_prefix[i] = (fib_prefix[i] + fib_prefix[i - 1]) % MOD;
    // Handle the queries using a Segment Tree
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        a[i] = (a[i] + a[i - 1]) % MOD;
    init(n);
    while (q--) {
        int type, l, r;
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1)
            modify(l - 1, r, 1, 0, sz);
        else
            printf("%d\n",
                   (query(l - 1, r, 1, 0, sz) + (a[r] - a[l - 1] + MOD) % MOD) %
                       MOD);
    }
}