#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    vector<vector<ll>> dp(h, vector<ll>(w, 0ll));
    for (int i = 0; i < h; i++)
        cin >> grid[i];
    dp[0][0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 && j == 0)
                continue;
            if (grid[i][j] == '#')
                dp[i][j] = 0;
            else
                dp[i][j] =
                    ((i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0)) %
                    MOD;
        }
    }
    cout << dp[h - 1][w - 1] << endl;
}