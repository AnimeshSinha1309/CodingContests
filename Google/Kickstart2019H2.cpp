#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<bool> vbl;
typedef vector<vector<long long>> mll;
typedef vector<vector<bool>> mbl;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpl;
#define minimize(a, b) (a = min(a, b);)
#define maximize(a, b) (a = max(a, b);)

enum State { SAME, OPPOSITE, FREE };

int main() {
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        // Taking the input
        ll n;
        cin >> n;
        mbl a(n, vbl(n, false));
        vector<vector<State>> match(2 * n - 1, vector<State>(2 * n - 1, FREE));
        mbl state(2, vbl(2 * n - 1, 0));
        for (int i = 0; i < n; i++) {
            string st;
            cin >> st;
            for (int j = 0; j < n; j++) {
                a[i][j] = (st[j] == '#');  // Get everyone to #
            }
        }
        // Assigning all the parities
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                match[i + j][i + n - 1 - j] = (a[i][j] ? SAME : OPPOSITE);
            }
        }
        // @debug
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < 2 * n - 1; j++)
                cout << match[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        // Assigning the final coloring
        for (int i = 0; i < 2 * n - 1; i++) {
            if (match[0][i] == SAME)
                state[1][i] = state[0][0];
            else if (match[0][i] == OPPOSITE)
                state[1][i] = !state[0][0];
        }
        for (int i = 0; i < 2 * n - 1; i++) {
            if (match[i][0] == SAME)
                state[0][i] = state[1][0];
            else if (match[0][i] == OPPOSITE)
                state[0][i] = !state[1][0];
        }
        // @debug
        for (int i = 0; i < 2 * n - 1; i++)
            cout << state[0][i] << " ";
        cout << endl;
        for (int i = 0; i < 2 * n - 1; i++)
            cout << state[1][i] << " ";
        cout << endl;
        // Check if the coloring is valid
        bool valid = true;
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                if ((state[0][i] != state[1][j] && match[i][j] == SAME) ||
                    state[0][i] == state[1][j] && match[i][j] == OPPOSITE)
                    valid = false;
            }
        }
        // Count the number of flips
        ll count = 0;
        for (int i = 0; i < 2 * n - 1; i++) {
            if (state[0][i])
                count++;
            if (state[1][i])
                count++;
        }
        cout << "Case #" << test << ": ";
        cout << (valid ? min(count, 2 * (n - 2) - count) : -1) << endl;
    }
}