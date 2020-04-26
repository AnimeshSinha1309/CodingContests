#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

ll n, k;

class Trie {
   public:
    struct Node {
        vector<Node *> next = vector<Node *>(27);
        int word_count = 0;
    };
    inline int letter_fn(char c) {
        if (c == '$')
            return 26;
        return c - 'A';
    };

    Node *root = new Node;
    void insert(const string &word, Node *node = nullptr, int position = 0) {
        if (node == nullptr)
            node = root;
        node->word_count++;
        if (position >= word.size())
            return;
        if (node->next[letter_fn(word[position])] == nullptr) {
            node->next[letter_fn(word[position])] = new Node;
        }
        insert(word, node->next[letter_fn(word[position])], position + 1);
    }

    // Returns (score achieved, people unresolved) - counts using $ in subtree
    pll dfs(Node *node, ll depth) {
        // Accumulate child results
        pll result = {0, 0};
        for (int i = 0; i < 26; i++) {
            if (node->next[i] != nullptr) {
                pll child_ans = dfs(node->next[i], depth + 1);
                result.first += child_ans.first;
                result.second += child_ans.second;
            }
        }
        // Count the $-ends here
        if (node->next[26] != nullptr)
            result.second += node->next[26]->word_count;
        result.first += (result.second / k) * depth;
        result.second %= k;
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cin >> n >> k;
        Trie trie;
        for (int i = 0; i < n; i++) {
            string in;
            cin >> in;
            in.append("$");
            trie.insert(in);
        }
        pll ans = trie.dfs(trie.root, 0);
        cout << "Case #" << test << ": " << ans.first << endl;
    }
}