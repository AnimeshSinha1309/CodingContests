#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long MAX_S = 1e5;
const long long MAX_N = 1e7;
ll totals[2 * MAX_N + 1];
ll a[MAX_S + 10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        ll n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll total = 0, ans = 0;
        totals[0 + MAX_N]++;
        for (int i = 0; i < n; i++) {
            total += a[i];
            for (int j = 0; j * j <= MAX_N + min(total, 0ll); j++) {
                ll add = totals[total - j * j + MAX_N];
                ans += add;
            }
            totals[total + MAX_N]++;
        }
        cout << "Case #" << test << ": " << ans << '\n';

        total = 0;
        totals[0 + MAX_N]--;
        for (int i = 0; i < n; i++) {
            total += a[i];
            totals[total + MAX_N]--;
        }
    }
}