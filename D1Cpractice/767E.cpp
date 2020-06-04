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
    ll n, m;
    cin >> n >> m;
    vll c(n), w(n);
    cin >> c >> w;
    ll ans = 0, cash = m;
    priority_queue<pll> q;
    vbl pay(n, false);
    for (int i = 0; i < n; i++) {
        cash += 100 - c[i] % 100;
        ll cost = w[i] * (100 - c[i] % 100);
        cout << "@DEBUG: " << cash << " " << cost << " " << ans << endl;
        if (cash >= 100) {
            pay[i] = true;
            cash -= 100;
            q.emplace(cost, i);
        } else if (!q.empty() && q.top().first > cost) {
            pay[i] = true, pay[q.top().second] = false;
            ans += cost - q.top().first;
            q.emplace(cost, i), q.pop();
        } else {
            pay[i] = false;
            ans += cost;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        if (pay[i])
            cout << c[i] / 100 << " " << c[i] % 100 << endl;
        else
            cout << c[i] / 100 + 1 << " " << 100 - c[i] % 100 << endl;
    }
}
