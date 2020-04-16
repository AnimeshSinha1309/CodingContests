// C++ program to demonstrate working of
// palindromic tree
#include "bits/stdc++.h"
using namespace std;

#define MAXN 1000000

struct Node {
    int start, end;
    int length;
    int insertEdg[26];
    int suffixEdg;
};

Node root1, root2;
Node tree[MAXN];
int currNode;
string s;
int ptr;

void insert(int idx) {
    int tmp = currNode;
    while (true) {
        int curLength = tree[tmp].length;
        if (idx - curLength >= 1 and s[idx] == s[idx - curLength - 1])
            break;
        tmp = tree[tmp].suffixEdg;
    }
    if (tree[tmp].insertEdg[s[idx] - 'a'] != 0) {
        currNode = tree[tmp].insertEdg[s[idx] - 'a'];
        return;
    }
    ptr++;
    tree[tmp].insertEdg[s[idx] - 'a'] = ptr;
    tree[ptr].length = tree[tmp].length + 2;
    tree[ptr].end = idx;
    tree[ptr].start = idx - tree[ptr].length + 1;

    tmp = tree[tmp].suffixEdg;
    currNode = ptr;
    if (tree[currNode].length == 1) {
        tree[currNode].suffixEdg = 2;
        return;
    }
    while (true) {
        int curLength = tree[tmp].length;
        if (idx - curLength >= 1 and s[idx] == s[idx - curLength - 1])
            break;
        tmp = tree[tmp].suffixEdg;
    }
    tree[currNode].suffixEdg = tree[tmp].insertEdg[s[idx] - 'a'];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        root1.length = -1;
        root1.suffixEdg = 1;
        root2.length = 0;
        root2.suffixEdg = 1;

        tree[1] = root1;
        tree[2] = root2;
        ptr = 2;
        currNode = 1;

        cin >> s;
        int n = s.length();

        for (int i = 0; i < n; i++)
            insert(i);

        vector<int> longest_from(n);
        vector<int> longest_to(n);

        for (int i = 3; i <= ptr; i++) {
            if (tree[i].start - 1 + tree[i].end <= n)
                longest_from[tree[i].start] =
                    max(longest_from[tree[i].start],
                        tree[i].end - tree[i].start + 1);
            if ((n - tree[i].end) * 2 + (tree[i].end - tree[i].start) <= n)
                longest_to[tree[i].end] = max(longest_to[tree[i].end],
                                              tree[i].end - tree[i].start + 1);
        }

        pair<long long, long long> ans = {0, 0};
        for (int common_len = 0; 2 * common_len < n; common_len++) {
            if (common_len > 0 && s[common_len - 1] != s[n - common_len])
                break;
            auto el = longest_from[common_len];
            if (common_len * 2 + el <= n &&
                common_len * 2 + el > ans.second + ans.first) {
                ans = {common_len + el, common_len};
            }
            el = longest_to[n - 1 - common_len];
            if (common_len * 2 + el <= n &&
                common_len * 2 + el > ans.second + ans.first) {
                ans = {common_len, common_len + el};
            }
        }
        for (int i = 0; i < ans.first; i++)
            cout << s[i];
        for (int i = n - ans.second; i < n; i++)
            cout << s[i];
        cout << endl;
    }
    return 0;
}
