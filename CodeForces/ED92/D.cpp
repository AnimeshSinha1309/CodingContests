#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
#define minimize(a, b) (a = min(a, b))
#define maximize(a, b) (a = max(a, b))

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        pll a, b;
        cin >> n >> k >> a.first >> a.second >> b.first >> b.second;
        if (a > b)
            swap(a, b);
        ll wait = b.first - a.second,
           gain = max(a.second, b.second) - min(a.first, b.first);
        if (k <= 0) {
            cout << 0 << '\n';
        } else if (wait <= 0) {
            k = max(k - abs(wait) * n, 0ll);
            gain = max(gain - abs(wait), 0ll);
            wait = 0;
            cout << min(gain * n, k) + max(k - gain * n, 0ll) * 2 << '\n';
        } else {
            ll ans = INT64_MAX;
            for (int i = 1; i <= n; i++) {
                minimize(ans, wait * i + min(gain * i, k) +
                                  max(k - gain * i, 0ll) * 2);
            }
            cout << ans << '\n';
        }
    }
}