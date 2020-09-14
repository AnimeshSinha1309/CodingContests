#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
const ll MOD = 1e9 + 7;

struct House {
    ll l, w, h, r;
    friend const bool operator<(House &a, House &b) {
        return a.l < b.l;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        // Take the inputs
        ll n, k, w;
        cin >> n >> k;
        vector<House> houses(n);
        ll a_l, b_l, c_l, d_l;
        ll a_h, b_h, c_h, d_h;
        ll a_w, b_w, c_w, d_w;
        for (int i = 0; i < k; i++)
            cin >> houses[i].l;
        cin >> a_l >> b_l >> c_l >> d_l;
        for (int i = 0; i < k; i++)
            cin >> houses[i].h;
        cin >> a_h >> b_h >> c_h >> d_h;
        for (int i = 0; i < k; i++)
            cin >> houses[i].w;
        cin >> a_w >> b_w >> c_w >> d_w;
        for (int i = k; i < n; i++)
            houses[i].l =
                (a_l * houses[i - 2].l + b_l * houses[i - 1].l + c_l) % d_l + 1;
        for (int i = k; i < n; i++)
            houses[i].h =
                (a_h * houses[i - 2].h + b_h * houses[i - 1].h + c_h) % d_h + 1;
        for (int i = k; i < n; i++)
            houses[i].w =
                (a_w * houses[i - 2].w + b_w * houses[i - 1].w + c_w) % d_w + 1;
        for (int i = 0; i < n; i++)
            houses[i].r = houses[i].w + houses[i].l;
        // Compute the perimeter
        sort(houses.begin(), houses.end());
        ll p = 0, g_max = 0, g_start = houses[0].l, g_end = houses[0].r,
           ans = 1;
        for (int i = 0; i < n; i++) {
            g_max = max(g_max, houses[i].h);
            ll val = (p + g_max * 2 + (houses[i].l + w - g_start) * 2) % MOD;
            cout << val << '*';
            if (i != n - 1 && houses[i + 1].l > g_end) {
                p = val;
                g_max = 0;
                g_start = houses[i + 1].l;
                g_end = houses[i + 1].r;
            }
            ans = (ans * val) % MOD;
        }

        // Print the output
        cout << "Case #" << test << ": " << ans << '\n';
    }
}