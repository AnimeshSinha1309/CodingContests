#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int n;
    cin >> n;
    vector<ld> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<vector<ld>> dp(n + 1, vector<ld>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i - 1; j++) {
            dp[i][j + 1] += dp[i - 1][j] * p[i - 1];
            dp[i][j] += dp[i - 1][j] * (1 - p[i - 1]);
        }
    }
    long double ans = 0;
    for (int i = n / 2 + 1; i <= n; i++) {
        ans += dp[n][i];
    }
    cout << setprecision(10) << ans << endl;
}