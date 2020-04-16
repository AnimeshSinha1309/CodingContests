// Solved by Dixit Garg - @dixitgarg
// Debugging Test Submission

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
const long long MOD = 998244353;

ll mod(ll a) {
    if (a < 0)
        a += MOD;
    if (a >= MOD)
        a -= MOD;
    return a;
}

struct Query {
    ll l, r, x;
};

ll solve(ll n, ll m, vector<Query>& queries, ll bit) {
    vll arr(n + 1, 0);
    vpl zero;
    zero.reserve(m);
    for (ll i = 0; i < m; i++) {
        ll x = queries[i].x;
        if ((x & (1ll << bit)) > 0) {
            arr[queries[i].l]++;
            arr[queries[i].r + 1]--;
        } else
            zero.emplace_back(queries[i].l, queries[i].r);
    }
    for (ll i = 1; i <= n; i++)
        arr[i] += arr[i - 1];
    for (ll i = 0; i < n; i++)
        if (arr[i] > 0)
            arr[i] = 1;
    vll vec;
    vec.reserve(n);
    for (ll i = 0; i < n; i++)
        if (arr[i] == 0)
            vec.push_back(i);
    vll L(n + 1, 0);
    if (arr[n - 1] == 0)
        L[n - 1] = n - 1;
    else
        L[n - 1] = n;
    for (ll i = n - 2; i >= 0; i--) {
        if (arr[i] == 0)
            L[i] = i;
        else
            L[i] = L[i + 1];
    }
    vll R(n, 0);
    if (arr[0] == 0)
        R[0] = 0;
    else
        R[0] = -1;
    for (ll i = 1; i < n; i++) {
        if (arr[i] == 0)
            R[i] = i;
        else
            R[i] = R[i - 1];
    }

    vll a(n, -1), b(n, -1);
    for (auto it : zero) {
        ll l1 = L[it.first], r1 = R[it.second];
        if (l1 > r1)
            return 0;
        if (a[l1] == -1 || a[l1] > r1)
            a[l1] = r1;
    }
    ll f = -1;
    for (ll i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            f = -1;
        } else {
            if (arr[i] == 1) {
                if (f == -1)
                    f = i;

                b[i] = f;
            }
        }
    }
    ll mn = n + 1;
    for (ll i = n - 1; i >= 0; i--) {
        if (a[i] != -1) {
            if (a[i] >= mn) {
                a[i] = -1;
            } else
                mn = a[i];
        }
    }
    mll dp(n + 1, vll(2, 0));
    vll suf(n + 1, 0);
    if (a[n - 1] == -1 && b[n - 1] == -1) {
        dp[n - 1][0] = 1;
        dp[n - 1][1] = 1;
    } else if (a[n - 1] == -1) {
        dp[n - 1][1] = 1;
        dp[n - 1][0] = 0;
    } else {
        dp[n - 1][0] = 1;
        dp[n - 1][1] = 0;
    }
    suf[n - 1] = dp[n - 1][0];
    for (ll i = n - 2; i >= 0; i--) {
        if (a[i] == -1 && b[i] == -1) {
            dp[i][0] = mod(dp[i + 1][0] + dp[i + 1][1]);
            dp[i][1] = mod(dp[i + 1][0] + dp[i + 1][1]);
        } else if (a[i] == -1) {
            dp[i][0] = 0;
            dp[i][1] = mod(dp[i + 1][0] + dp[i + 1][1]);
        } else {
            dp[i][0] = mod(dp[i + 1][0] + dp[i + 1][1]);
            if (a[i] == i) {
                dp[i][1] = 0;
            } else {
                dp[i][1] = suf[i + 1];
                if (a[i] != (n - 1))
                    dp[i][1] -= suf[a[i] + 1];
                dp[i][1] = mod(dp[i][1]);
            }
        }
        suf[i] = mod(suf[i + 1] + dp[i][0]);
    }
    return mod(dp[0][0] + dp[0][1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, k, m;
    cin >> n >> k >> m;
    vector<Query> queries(m);
    for (ll i = 0; i < m; i++) {
        ll l, r, x;
        cin >> queries[i].l >> queries[i].r >> queries[i].x;
        queries[i].l--, queries[i].r--;
    }
    ll ans = 1;
    for (ll i = 0; i < k; i++) {
        ans *= solve(n, m, queries, i);
        if (ans > MOD)
            ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}