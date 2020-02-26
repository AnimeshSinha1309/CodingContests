#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    unsigned int n; cin >> n;
    vector<long long> a(n); for (auto &item : a) cin >> item;
    vector<long long> f(100001, 0); for (const auto &item : a) f[item]++;
    vector<long long> dp(100001, 0); dp[1] = f[1];
    for (int i = 2; i <= 100000; i++) {
        dp[i] = max(i * f[i] + dp[i-2], dp[i-1]);
    } cout << dp[100000] << endl;
}