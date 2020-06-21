#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<vll> mll;
typedef vector<pll> vpl;

inline ll solve(ll a) {
    ll b = a;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            ll c = 1;
            while (a % i == 0)
                a /= i, c *= i;
            if (b / c != 1)
                return c;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Take the inputs
    ll n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vpl ans(n);
    // Solve
    for (int i = 0; i < n; i++) {
        ans[i].first = solve(a[i]);
        ans[i].second = ans[i].first == -1 ? -1 : a[i] / ans[i].first;
    }
    // Print the answers
    for (int i = 0; i < n; i++)
        cout << ans[i].first << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i].second << ' ';
    cout << '\n';
}