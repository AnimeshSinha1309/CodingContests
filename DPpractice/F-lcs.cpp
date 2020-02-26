#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int main() {
    string s, t;
    cin >> s >> t;
    ll n = s.size(), m = t.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans = "";
    for (int i = n, j = m; i > 0 && j > 0;) {
        if (dp[i][j] > max(dp[i - 1][j], dp[i][j - 1]))
            ans = s[i - 1] + ans, i--, j--;
        else
            (dp[i - 1][j] > dp[i][j - 1]) ? i-- : j--;
    }
    cout << ans << endl;
}