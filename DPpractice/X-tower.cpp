#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long long, long long> pll;
#define minimize(var, val) (var = min((val), var))
#define maximize(var, val) (var = max((val), var))
const long long MOD = 1e9 + 7;

struct Box {
    ll weight = 0, strength = 0, value = 0;
    friend bool operator<(Box a, Box b) {
        return (a.strength + a.weight) < (b.strength + b.weight);
    }
};

int main() {
    ll n;
    cin >> n;
    vector<Box> b(n);
    for (ll i = 0; i < n; i++)
        cin >> b[i].weight >> b[i].strength >> b[i].value;
    sort(b.begin(), b.end());
    mll dp(n + 1, vll(20001, 0));
    for (ll i = 0; i < n; ++i) {
        for (ll net_weight = 0; net_weight <= 20000; ++net_weight) {
            if (b[i].strength >= net_weight &&
                net_weight + b[i].weight <= 20000)
                maximize(dp[i + 1][net_weight + b[i].weight],
                         dp[i][net_weight] + b[i].value);
            maximize(dp[i + 1][net_weight], dp[i][net_weight]);
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
}
