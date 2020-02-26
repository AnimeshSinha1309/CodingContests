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
const long long MOD = 1e9 + 7;

ll inverse(ll val) {
    ll power = MOD - 2;
    ll res = 1, cum = (val % MOD);
    for (; power > 0; power >>= 1) {
        if (power & 1)
            res = (res * cum) % MOD;
        cum = (cum * cum) % MOD;
    }
    return res;
}

vll factorial(200001, 1), ifactorial(200001, 1), wt(200001, 0);
ll c(ll n, ll r) {
    return (factorial[n] * ((ifactorial[r] * ifactorial[n - r]) % MOD)) % MOD;
}

int main() {
    for (int i = 1; i <= 200000; i++)
        factorial[i] = (factorial[i - 1] * i) % MOD;
    for (int i = 1; i <= 200000; i++)
        ifactorial[i] = inverse(factorial[i]);
    // Compute the number of times each factor is to be counted
    wt[1] = 1;
    for (int i = 2, j; i <= 200000; i++) {
        wt[i] -= wt[1];
        for (j = 2; j * j < i; j++) {
            if (i % j == 0) {
                wt[i] -= wt[j];
                wt[i] -= wt[i / j];
            }
        }
        if (j * j == i)
            wt[i] -= wt[j];
    }
    for (int i = 2, j; i <= 200000; i++)
        wt[i] = (wt[i] + MOD) % MOD;
    ll t;
    scanf("%lld", &t);
    while (t--) {
        // Take input and compute factors
        ll n, f;
        scanf("%lld %lld", &n, &f);
        ll i, ans = 0;
        for (i = 1; i * i < n; i++) {
            if (n % i == 0) {
                if (i >= f)
                    ans = (ans + ((c(i - 1, f - 1) * wt[n / i]) % MOD)) % MOD;
                if (n / i >= f)
                    ans = (ans + ((c(n / i - 1, f - 1) * wt[i]) % MOD)) % MOD;
            }
        }
        if (i * i == n) {
            if (i >= f)
                ans = (ans + ((c(i - 1, f - 1) * wt[i]) % MOD)) % MOD;
        }
        printf("%lld\n", ans);
    }
}