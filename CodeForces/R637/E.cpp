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

ll n, m, g, r;
mll cache;
vll a;

ll dp(ll pos, ll time) {
    // Handle invalid or solved problems
    if (cache[pos][time])
        return cache[pos][time];
    // Go to higher position
    if (pos < a.size() - 1) {
        ll dist_1 = a[pos + 1] - a[pos];
        if (time == dist_1)
            minimize(cache[pos][time], dp(pos + 1, g) + dist_1 + r);
        else if (time > dist_1)
            minimize(cache[pos][time], dp(pos + 1, time - dist_1) + dist_1);
    }
    // Go to lower position
    if (pos > 0) {
        ll dist_2 = a[pos] - a[pos - 1];
        if (time == dist_2)
            dp(pos - 1, g, dist + dist_2 + r);
        else if (time > dist_2)
            dp(pos - 1, time - dist_2, dist + dist_2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    a = vll(m);
    cin >> a;
    cin >> g >> r;
    cache = mll(m + 1, vll(g + 1, INT64_MAX));
    dp()
}