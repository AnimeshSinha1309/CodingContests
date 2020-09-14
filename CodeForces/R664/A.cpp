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
#define clip(val, top, bot) (max(bot, min(top, val)))
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
    ll n, d, m;
    cin >> n >> d >> m;
    vll a(n);
    cin >> a;
    vll a1, a2;
    a1.reserve(n), a2.reserve(n);
    for (auto el : a)
        el > m ? a1.push_back(el) : a2.push_back(el);
    sort(a1.rbegin(), a1.rend());
    sort(a2.rbegin(), a2.rend());
    for (int i = 1; i < a1.size(); i++)
        a1[i] += a1[i - 1];
    for (int i = 1; i < a2.size(); i++)
        a2[i] += a2[i - 1];

    ll ans = a2.back();
    for (int i = 1; i <= a1.size(); i++) {
        if (i * (d + 1) < n + d) {
            maximize(
                ans,
                a1[i - 1] + a2[min((ll)a2.size(), n + d - i * (d + 1)) - 1ll]);
        }
    }
    cout << ans << endl;
}