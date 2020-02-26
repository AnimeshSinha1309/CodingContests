#include <iostream>
#include <vector>
using namespace std;

#define INF (1ll << 50)
#define VAL (100001)
typedef long long ll;
#define minimize(var, val) (var = min((val), var))

int main() {
    ll n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> obj(n);
    for (int i = 0; i < n; i++)
        cin >> obj[i].second >> obj[i].first;
    vector<ll> dp(VAL, INF);
    dp[0] = 0;
    vector<ll> next(VAL);
    for (int i = 0; i < n; i++) {
        next = dp;
        for (int j = obj[i].first; j <= VAL; j++) {
            minimize(next[j], dp[j - obj[i].first] + obj[i].second);
        }
        dp = next;
    }
    long long top = 0;
    for (int i = 0; i < VAL; i++)
        if (dp[i] <= w)
            top = i;
    cout << top << endl;
}