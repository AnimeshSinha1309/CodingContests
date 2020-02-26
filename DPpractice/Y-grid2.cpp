#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long long, long long> pll;
#define minimize(var, val) (var = min((val), var))

class ModfieldInt {
   public:
    long long value;
    const static long long mod = 1e9 + 7;
    ModfieldInt(long long value = 0) {
        this->value = value;
    }
    friend ModfieldInt operator^(ModfieldInt val, long long power) {
        long long res = 1, cum = (val.value % val.mod);
        for (; power > 0; power >>= 1) {
            if (power & 1)
                res = (res * cum) % val.mod;
            cum = (cum * cum) % val.mod;
        }
        return ModfieldInt(res);
    }
    friend ModfieldInt operator+(ModfieldInt a, ModfieldInt b) {
        return ModfieldInt((a.value + b.value) % b.mod);
    }
    friend ModfieldInt operator-(ModfieldInt a, ModfieldInt b) {
        return ModfieldInt((a.value - b.value + b.mod) % b.mod);
    }
    friend ModfieldInt operator*(ModfieldInt a, ModfieldInt b) {
        return ModfieldInt((a.value * b.value) % a.mod);
    }
    friend ModfieldInt operator/(ModfieldInt a, ModfieldInt b) {
        return a * (b ^ (b.mod - 2));
    }
};

vector<ModfieldInt> factorial(200001, 1);

ModfieldInt comb(ll n, ll r) {
    return factorial[n] / (factorial[r] * factorial[n - r]);
}

int main() {
    // Precompute nCr to find out number of ways from cell to cell
    factorial[0] = 1;
    for (int i = 1; i <= 200000; i++)
        factorial[i] = factorial[i - 1] * ModfieldInt(i);
    // Take all the inputs and sort them in the lattice structure
    ll h, w, n;
    cin >> h >> w >> n;
    vpl a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    // Compute for each number of ways it can be the first forbidden hit
    vector<ModfieldInt> dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[i] = comb(a[i].first + a[i].second - 2, a[i].first - 1);
        for (int j = 0; j < i; j++) {
            if (a[i].second >= a[j].second && a[i].first >= a[j].first)
                dp[i] = dp[i] - comb(a[i].first + a[i].second - a[j].first -
                                         a[j].second,
                                     a[i].first - a[j].first) *
                                    dp[j];
        }
    }
    // Same computation for the last square
    ModfieldInt ans = comb(h + w - 2, h - 1);
    for (int j = 0; j < n; j++) {
        ans = ans -
              comb(h + w - a[j].first - a[j].second, h - a[j].first) * dp[j];
    }
    // Output the answer
    cout << ans.value << endl;
}
