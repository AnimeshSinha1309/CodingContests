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
        ll n, k;
        cin >> n >> k;
        vll s(n), x(n), y(n);
        ll a_s, b_s, c_s, d_s;
        ll a_x, b_x, c_x, d_x;
        ll a_y, b_y, c_y, d_y;
        for (int i = 0; i < k; i++)
            cin >> s[i];
        cin >> a_s >> b_s >> c_s >> d_s;
        for (int i = 0; i < k; i++)
            cin >> x[i];
        cin >> a_x >> b_x >> c_x >> d_x;
        for (int i = 0; i < k; i++)
            cin >> y[i];
        cin >> a_y >> b_y >> c_y >> d_y;
        for (int i = k; i < n; i++)
            s[i] = (a_s * s[i - 2] + b_s * s[i - 1] + c_s) % d_s;
        for (int i = k; i < n; i++)
            x[i] = (a_x * x[i - 2] + b_x * x[i - 1] + c_x) % d_x;
        for (int i = k; i < n; i++)
            y[i] = (a_y * y[i - 2] + b_y * y[i - 1] + c_y) % d_y;
        // Compute the perimeter
        ll ans = 0, forced_give = 0, forced_take = 0, available_give = 0,
           available_take = 0;
        for (int i = 0; i < n; i++) {
            ll bot = x[i] - s[i], top = x[i] + y[i] - s[i];
            if (top < 0) {
                forced_take += -top;
                available_take += top - bot;
            } else if (bot > 0) {
                forced_give += bot;
                available_give += top - bot;
            } else {
                available_give += top;
                available_take += -bot;
            }
        }
        ll tr_forced = min(forced_give, forced_take);
        forced_give -= tr_forced, forced_take -= tr_forced;
        ll tr_give = min(forced_give, available_take);
        forced_give -= tr_give, available_take -= tr_give;
        ll tr_take = min(forced_take, available_give);
        forced_take -= tr_take, available_give -= tr_take;
        if (forced_give != 0 || forced_take != 0) {
            ans = -1;
        } else {
            ans = tr_forced + tr_give + tr_take;
        }
        // Print the output
        cout << "Case #" << test << ": " << ans << '\n';
    }
}