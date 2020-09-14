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

void solve() {
    ll n, k, l;
    cin >> n >> k >> l;
    vll d(n);
    cin >> d;
    vbl safe(n);
    for (int i = 0; i < n; i++) {
        safe[i] = (d[i] + k) <= l;
        if (d[i] > l) {
            cout << "NO\n";
            return;
        }
    }

    ll time = -(k + 1);
    for (int i = 0; i < n; i++) {
        if (time < 0) {
            time = max(time + 1, -(l - d[i]));
        } else if (time < (l - d[i])) {
            time++;
        } else {
            cout << "NO\n";
            return;
        }
        if (safe[i]) {
            time = -(k + 1);
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}