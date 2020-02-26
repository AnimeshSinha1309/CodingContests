// Accepted
// Tags: #Trivial #DynamicProgramming

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, q;
        cin >> n >> q;
        string st;
        cin >> st;
        vector<vector<int>> count(1, vector<int>(26, 0));
        count.reserve(n + 1);
        vector<int> current(26, 0);
        for (int i = 0; i < n; i++) {
            current[(unsigned int)(st[i] - 'A')]++;
            count.push_back(current);
        }
        int result = 0;
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            int parity = 0;
            for (int j = 0; j < 26; j++) {
                parity += (count[r][j] - count[l - 1][j]) % 2;
            }
            if (parity <= 1)
                result++;
        }
        cout << "Case #" << test << ": " << result << endl;
    }
}