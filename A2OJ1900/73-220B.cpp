#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r;
    int index;
    int result;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Take the inputs
    unsigned int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<Query> q(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].l--, q[i].r--;
        q[i].index = i;
    }
    // Mo's algorithm preparation
    unsigned int block_size = (unsigned int)sqrt(n), block_count = n / block_size + 1;
    assert(block_size * block_count >= n);
    a.resize(block_size * block_count, 0);
    sort(q.begin(), q.end(), [block_size](Query a, Query b) {
        return (a.l / block_size == b.l / block_size) ? a.r < b.r : a.l < b.l;
    });
    // Sort and solve
    vector<int> freq(n + 1);
    int count = 0;
    int ptr_l = 0, ptr_r = -1;  // both inclusive
    for (int i = 0, block = 0; i < m; i++) {
        // Reset the left pointer after the query block (clear)
        if (q[i].l >= block * block_size) {
            freq.assign(n, 0);
            ptr_l = 0, ptr_r = -1, count = 0;
            block++;
        }
        // Handle the right pointer moving right (insertions)
        while (ptr_r < q[i].r) {
            if (a[ptr_r + 1] > n) {
                ptr_r++;
                continue;
            }
            freq[a[++ptr_r]] += 1;
            if (freq[a[ptr_r]] == a[ptr_r]) {
                count++;
            } else if (freq[a[ptr_r]] == a[ptr_r] + 1) {
                count--;
            }
        }
        // Handle the left pointer moving right (deletions)
        while (ptr_l < q[i].l) {
            if (a[ptr_l] > n) {
                ptr_l++;
                continue;
            }
            freq[a[ptr_l++]] -= 1;
            if (freq[a[ptr_l - 1]] == a[ptr_l - 1]) {
                count++;
            } else if (freq[a[ptr_l - 1]] == a[ptr_l - 1] - 1) {
                count--;
            }
        }
        // Handle the left pointer moving left (insertions)
        while (ptr_l > q[i].l) {
            if (a[ptr_l - 1] > n) {
                ptr_l--;
                continue;
            }
            freq[a[--ptr_l]] += 1;
            if (freq[a[ptr_l]] == a[ptr_l]) {
                count++;
            } else if (freq[a[ptr_l]] == a[ptr_l] + 1) {
                count--;
            }
        }
        // Print the result
        q[i].result = count;
    }
    sort(q.begin(), q.end(),
         [](Query a, Query b) { return a.index < b.index; });
    for (int i = 0; i < m; i++)
        printf("%d\n", q[i].result);
}