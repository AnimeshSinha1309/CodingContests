#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<pair<long long, long long>> vpl;

/**
 * Solves the single-use Discrete (0-1) Knapsack problem.
 * Params: A vector of objects as {volume, value}, and an integer max-weight
 * Returns: A vector of max_value vs. volume occupied
 */

vll knapsack(const vpl &obj, ll max_weight) {
    ll n = obj.size();
    vll dp(max_weight + 1, 0);
    for (int i = 0; i < n; i++) {
        vll next(max_weight + 1, 0);
        for (int j = 0; j <= max_weight; j++) {
            next[j] = obj[i].first > j
                          ? dp[j]
                          : max(dp[j], dp[j - obj[i].first] + obj[i].second);
            if (j > 0)
                next[j] = max(next[j], next[j - 1]);
        }
        dp = next;
    }
    return dp;
}

int main() {
    long long n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> obj(n);
    for (int i = 0; i < n; i++)
        cin >> obj[i].first >> obj[i].second;
    vll dp = knapsack(obj, k);
    cout << dp[k] << endl;
}