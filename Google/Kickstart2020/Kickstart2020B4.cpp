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

template<typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
    ll n = vec.size();
    for (int i = 0; i < n; i++)
        in >> vec[i];
    return in;
}

template<typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    out << endl;
    return out;
}

inline vld prob(ll x, ll y) {
    vld dp(y, 0);
    dp[0] = 1.0;
    for (int i = 1; i < x; i++) {
        dp[0] /= 2.0;
    }
    for (int i = 1; i < y; i++) {
        dp[i] = dp[i - 1] * (x - 1 + i) / (i * 2.0);
    }
    return dp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; test++) {
        ll w, h, l, u, r, d; cin >> w >> h >> l >> u >> r >> d;
        vld dp_u = prob(u, w), dp_l = prob(l, h);
        vld dp_h(w, 0.0l), dp_w(h, 0.0l);
        // Compute the H - vector
        if (h == 1) {
            dp_h.assign(w, 1.0l);
        } else {
            dp_h = prob(h - 1, w);
            dp_h[0] /= 2.0;
            for (int i = 1; i < h; i++) {
                dp_h[i] = dp_h[i - 1] + dp_h[i] / 2.0;
            }
        }
        // Compute the W - vector
        if (w == 1) {
            dp_w.assign(h, 1.0l);
        } else {
            dp_w = prob(w - 1, h);
            dp_w[0] /= 2.0;
            for (int i = 1; i < h; i++) {
                dp_w[i] = dp_w[i - 1] + dp_w[i] / 2.0;
            }
        }
        // Fix all errors
        dp_h[w - 1] = 1.0, dp_w[h - 1] = 1.0;
        if (u == h) dp_u = dp_h;
        if (l == w) dp_l = dp_w;
        if (u != h) dp_u[w - 1] = dp_w[u - 1];
        if (u != h) dp_l[h - 1] = dp_h[l - 1];
        // Answer the questions
        ld ans = dp_u[l - 1];
        for (int i = l; i < r; i++) {
            ans += dp_u[i] - (u == h ? 1.0 : 0.5) * dp_u[i - 1];
        }
        for (int j = u; j < d; j++) {
            ans += dp_l[j] - (l == w ? 1.0 : 0.5) * dp_l[j - 1];
        }
        cout << "Case #" << test << ": " << 1.0l - ans << endl;
    }
}