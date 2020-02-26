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

ll check(ll max_speed, ll ender, const ll &k, const ll &n) {
    if (max_speed >= ender) {
        ll n = (max_speed - 1) - ender + 1;
        ll dist_travelled =
            max_speed * (max_speed + 1) / 2 + n * (2 * ender + n - 1) / 2;
        if (dist_travelled > k)
            return -1;
        ll dist_remain = k - dist_travelled;
        ll time = max_speed + n;
        ll extra = dist_remain / max_speed;
        time += extra;
        dist_remain -= max_speed * extra;
        if (dist_remain)
            time++;
        return time;
    } else {
        ll dist_travelled = max_speed * (max_speed + 1) / 2;
        if (dist_travelled > k)
            return -1;
        ll dist_remain = k - dist_travelled;
        ll time = max_speed;
        ll extra = dist_remain / max_speed;
        time += extra;
        dist_remain -= max_speed * extra;
        if (dist_remain)
            time++;
        return time;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    ll k, n;
    cin >> k >> n;
    while (n--) {
        ll x;
        cin >> x;
        ll b = 1, e = 1e5, ans = 1e15;
        while (b <= e) {
            ll m = (b + e) / 2;
            ll time = check(m, x, k, n);
            (time > -1) ? b = m + 1, minimize(ans, time) : e = m - 1;
        }
        cout << ans << endl;
    }
    return 0;
}