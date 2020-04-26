/**
 * Topic: Dynamic Programming with Bit-masks, probability
 * Idea: Computing a D
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef long double ld;
typedef vector<long double> vld;
typedef vector<vector<long double>> mld;
typedef vector<bool> vbl;
typedef vector<vector<bool>> mbl;
#define minimize(a, b) (a = min(a, b))
#define maximize(a, b) (a = max(a, b))
const long long MOD = (ll)1e9 + 7;

template<typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
    ll n = vec.size();
    for (int i = 0; i < n; i++)
        in >> vec[i];
    return in;
}

template<typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    out << endl;
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n; cin >> n;
    mld p(n, vld(n, 0)); cin >> p;
    vld dp(1 << n, 0.0l);
    dp[(1 << n) - 1] = 1.0; // dp[set] = prob of set surviving
    for (int fish_set = (1 << n) - 1; fish_set > 0; fish_set--) {
        int fishes = __builtin_popcount(fish_set);
        ld fight_prob = 1.0l / (fishes * (fishes - 1) / 2.0l);
        if (fishes <= 1)
            continue;
        for (int fish_loser = 0; fish_loser < n; ++fish_loser) {
            if ((fish_set & (1 << fish_loser)) == 0)
                continue;
            // dp[winners set] = net probability of any winner eating loser on first encounter
            int winners_set = fish_set & ~(1 << fish_loser);
            for (int fish_winner = 0; fish_winner < n; ++fish_winner) {
                if ((fish_set & (1 << fish_winner)) == 0)
                    continue;
                dp[winners_set] += p[fish_winner][fish_loser] * dp[fish_set] * fight_prob;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(6) << dp[1 << i] << " ";
    }
    cout << endl;
}