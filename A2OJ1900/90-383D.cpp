#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define DP(pos, val) dp[pos][val+10000]
#define MOD 1000000007

int main() {
    unsigned int n; cin >> n;
    vector<long long> list(n);
    for (auto &item : list) cin >> item;
    long long alpha = list[n];
    vector<vector<long long>> dp(n, vector<long long>(20001, 0));
    for (int i = 0; i < n; i++) {
        for (int j = -10000; i > 0 && j <= 10000; j++) {
            if (DP(i-1, j) != 0) DP(i, j + list[i]) = (DP(i, j + list[i]) + DP(i-1, j)) % MOD;
            if (DP(i-1, j) != 0) DP(i, j - list[i]) = (DP(i, j - list[i]) + DP(i-1, j)) % MOD;
        }
        DP(i,  list[i]) = (DP(i,  list[i]) + 1) % MOD;
        DP(i, -list[i]) = (DP(i, -list[i]) + 1) % MOD;
    }
    long long result = 0;
    for (int i = 0; i < n; i++) result = (result + DP(i, 0)) % MOD;
    cout << result;
}