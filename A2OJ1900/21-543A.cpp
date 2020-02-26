#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned long long n, m, b, mod; cin >> n >> m >> b >> mod;
    vector<long long> p(n); for (int i = 0; i < n; i++) cin >> p[i];
    vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(n, vector<long long>(b + 1, 0)));
    dp[0][0][0] = 1;
    for (int day = 0; day < m; day++) { // We have fed forward till day m but not changed personnel on the last day
        for (int coder = 0; coder < n - 1; coder++) // Change of Personnel
            for (int bugs = 0; bugs <= b; bugs++)
                dp[day % 2][coder + 1][bugs] = (dp[day % 2][coder + 1][bugs] + dp[day % 2][coder][bugs]) % mod;
        for (int coder = 0; coder < n; coder++) // Reset the array for the next day
            for (int bugs = 0; bugs <= b; bugs++)
                dp[(day + 1) % 2][coder][bugs] = 0;
        for (int coder = 0; coder < n; coder++) // Code on the next day
            for (int bugs = 0; bugs <= b; bugs++)
                if (bugs + p[coder] <= b)
                    dp[(day + 1) % 2][coder][bugs + p[coder]] =
                            (dp[(day + 1) % 2][coder][bugs + p[coder]] + dp[day % 2][coder][bugs]) % mod;
    }
    long long result = 0;
    for (int coder = 0; coder < n; coder++)
        for (int bugs = 0; bugs <= b; bugs++)
            result = (result + dp[m % 2][coder][bugs]) % mod;
    cout << result << endl;
}