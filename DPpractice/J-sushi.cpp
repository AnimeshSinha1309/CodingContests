#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long long, long long> pll;
#define minimize(var, val) (var = min((val), var))
const long long MOD = 1e9 + 7;

ld dp[301][301][301];
bool solved[301][301][301];
ll n;

ld path_length(ll a, ll b, ll c) {
    if (a == 0 && b == 0 && c == 0)
        return 0;
    if (dp[a][b][c] >= 0)
        return dp[a][b][c];
    ld result = 0;
    if (a > 0)
        result += ((ld)a / (a + b + c)) * (1 + path_length(a - 1, b, c));
    if (b > 0)
        result += ((ld)b / (a + b + c)) * (1 + path_length(a + 1, b - 1, c));
    if (c > 0)
        result += ((ld)c / (a + b + c)) * (1 + path_length(a, b + 1, c - 1));
    result += (ld)(n - a - b - c) / (a + b + c);
    dp[a][b][c] = result;
    return result;
}

int main() {
    // Reset DP and take the inputs
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                dp[i][j][k] = -1;
    // Compute the final result
    ll x = 0, y = 0, z = 0;
    for (int a_i : a) {
        if (a_i == 1)
            x++;
        if (a_i == 2)
            y++;
        if (a_i == 3)
            z++;
    }
    cout << setprecision(20) << path_length(x, y, z) << endl;
}