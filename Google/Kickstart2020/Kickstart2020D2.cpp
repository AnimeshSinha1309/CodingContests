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

template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
    ll n = vec.size();
    for (int i = 0; i < n; i++)
        in >> vec[i];
    return in;
}
template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    out << endl;
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        ll n;
        cin >> n;
        vll a(n);
        cin >> a;
        vll dp(4, 0);
        for (int i = 1; i < n; i++) {
            vll next(4, INT64_MAX);
            for (int new_pitch = 0; new_pitch < 4; new_pitch++) {
                for (int old_pitch = 0; old_pitch < 4; old_pitch++) {
                    if ((a[i] > a[i - 1] && new_pitch > old_pitch) ||
                        (a[i] < a[i - 1] && new_pitch < old_pitch) ||
                        (a[i] == a[i - 1] && new_pitch == old_pitch))
                        minimize(next[new_pitch], dp[old_pitch]);
                    else
                        minimize(next[new_pitch], dp[old_pitch] + 1);
                }
            }
            dp = next;
        }
        ll ans = *min_element(dp.begin(), dp.end());
        cout << "Case #" << test << ": " << ans << endl;
    }
}