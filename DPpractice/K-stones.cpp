#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define WIN true
#define LOSE false

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<bool> dp(k + 1);
    for (int i = 0; i <= k; i++) {
        dp[i] = LOSE;
        for (auto stones : a) {
            if (i >= stones && dp[i - stones] == LOSE)
                dp[i] = WIN;
        }
    }
    cout << (dp[k] == WIN ? "First" : "Second") << endl;
}