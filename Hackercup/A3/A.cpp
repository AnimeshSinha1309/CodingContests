#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        // Take the inputs
        ll n, k, w;
        cin >> n >> k >> w;
        vll l(n), h(n);
        ll a_l, b_l, c_l, d_l;
        ll a_h, b_h, c_h, d_h;
        for (int i = 0; i < k; i++)
            cin >> l[i];
        cin >> a_l >> b_l >> c_l >> d_l;
        for (int i = 0; i < k; i++)
            cin >> h[i];
        cin >> a_h >> b_h >> c_h >> d_h;
        for (int i = k; i < n; i++)
            l[i] = (a_l * l[i - 2] + b_l * l[i - 1] + c_l) % d_l + 1;
        for (int i = k; i < n; i++)
            h[i] = (a_h * h[i - 2] + b_h * h[i - 1] + c_h) % d_h + 1;
        // Compute the perimeter
        ll p = 0, g_max = 0, g_start = l[0], ans = 1;
        for (int i = 0; i < n; i++) {
            g_max = max(g_max, h[i]);
            ll val = (p + g_max * 2 + (l[i] + w - g_start) * 2) % MOD;
            cout << val << '*';
            if (i != n - 1 && l[i + 1] - l[i] > w) {
                p = val;
                g_max = 0;
                g_start = l[i + 1];
            }
            ans = (ans * val) % MOD;
        }
        // Print the output
        cout << "Case #" << test << ": " << ans << '\n';
    }
}