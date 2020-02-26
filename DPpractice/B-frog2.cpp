#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long sum = 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> dp(n, INT64_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= min(i, (int)k); j++)
            dp[i] = min(dp[i - j] + abs(a[i] - a[i - j]), dp[i]);
    cout << dp[n - 1] << endl;
}