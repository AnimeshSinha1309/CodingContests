#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long long, long long> pll;
#define minimize(var, val) (var = min((val), var))

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mll dp_max(n, vll(n, 0)), dp_min(n, vll(n, 0));
    for (int i = 0; i < n; i++)
        dp_max[i][i] = a[i];
    for (int i = 0; i < n; i++)
        dp_min[i][i] = -a[i];
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = len + i - 1;
            dp_max[i][j] =
                max(a[i] + dp_min[i + 1][j], dp_min[i][j - 1] + a[j]);
            dp_min[i][j] =
                min(dp_max[i + 1][j] - a[i], dp_max[i][j - 1] - a[j]);
        }
    }
    cout << dp_max[0][n - 1] << endl;
}