#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpl;
typedef vector<bool> vbl;
const long long MOD = 1000000007;

vll digits(1e6 + 1, 0);

pair<ll, bool> mod_power(ll a, ll b, ll mod) {
    if (b < 0)
        return {1, false};
    ll cumulative = a, result = 1;
    bool overflow = false;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1) {
            result *= cumulative;
            if (result > mod)
                result %= mod, overflow = true;
        }
        cumulative *= cumulative;
        if (cumulative > mod)
            cumulative %= mod, overflow = true;
    }
    return make_pair(result % mod, overflow);
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, p;
        cin >> n >> p;
        set<ll, greater<>> indices;
        vll k(n);
        for (int i = 0; i < n; i++)
            cin >> k[i];
        for (int i = 0; i < n; i++) {
            if (digits[k[i]] == 0)
                indices.insert(k[i]);
            digits[k[i]]++;
        }
        ll demand = 0;
        bool game_over = false;

        int prev_idx = -1;
        for (auto idx : indices) {
            pair<ll, bool> res = mod_power(p, prev_idx - idx, MOD);
            ll multiplier = res.first;
            prev_idx = idx;
            if (res.second || multiplier > 1e7)
                game_over = true;

            if (game_over) {
                demand = (demand * multiplier - digits[idx] + MOD) % MOD;
            } else {
                if (demand > 1e7)
                    game_over = true, demand %= MOD;
                demand = demand * multiplier;
                demand = (demand >= digits[idx]) ? (demand - digits[idx])
                                                 : (digits[idx] - demand) % 2;
                if (demand > 1e7)
                    game_over = true, demand %= MOD;
            }
        }
        cout << (demand * mod_power(p, *prev(indices.end()), MOD).first) % MOD
             << endl;
        for (auto el : indices)
            digits[el] = 0;
    }
}