#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        // Take the inputs
        ll n;
        ld p;
        cin >> n >> p;
        vld stay(n, 1.0);
        vld ans(n, 0.0);
        for (int day = 0; day < n - 1; day++) {
            ld pair_prob = 0.0;
            for (int i = 0; i < n; i++)
                pair_prob += stay[i] * (n - day - stay[i]);
            pair_prob /= 2.0;
            ld stronger = n - day;
            for (int i = 0; i < n; i++) {
                stronger -= stay[i];
                ld others = n - day - stay[i], weaker = others - stronger;
                ans[i] += stay[i];
                ld sel_prob = (stay[i] * (n - day - stay[i])) / pair_prob;
                ld el_prob =
                    sel_prob * (p * stronger + (1 - p) * weaker) / others;
                stay[i] = (stay[i] - el_prob);
            }
        }
        cout << setprecision(10) << fixed;
        cout << "Case #" << test << ": \n";
        for (int i = 0; i < n; i++) {
            cout << ans[i] << '\n';
        }
    }
}