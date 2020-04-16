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
    ll n;
    cin >> n;
    vll p(n);
    cin >> p;
    for (int i = 0; i < n; i++)
        p[i]--;
    vll c(n);
    cin >> c;
    // Prepare all permutation cycles
    ll cnt = 0;
    mll cycles(n);
    vbl used(n, false);
    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;
        cycles[cnt].push_back(i);
        used[i] = true;
        for (int j = p[i]; j != i; j = p[j]) {
            cycles[cnt].push_back(j);
            used[j] = true;
        }
        cnt++;
    }
    cycles.resize(cnt);
    // Find loops in the cycles
    ll ans = INT64_MAX;
    for (auto cycle : cycles) {
        ll size = cycle.size();
        for (ll shift = 1; shift * shift <= size; shift++) {
            if (size % shift != 0)
                continue;
            ll shift_1 = shift, shift_2 = size / shift;
            // Shift 1
            for (ll i = 0; i < shift_1; i++) {
                bool works = true;
                for (int j = i; j + shift_1 < size; j += shift_1) {
                    if (c[cycle[j]] != c[cycle[j + shift_1]]) {
                        works = false;
                        break;
                    }
                }
                if (works) {
                    minimize(ans, shift_1);
                }
            }
            // Shift 2
            for (ll i = 0; i < shift_2; i++) {
                bool works = true;
                for (int j = i; j + shift_2 < size; j += shift_2) {
                    if (c[cycle[j]] != c[cycle[j + shift_2]]) {
                        works = false;
                        break;
                    }
                }
                if (works) {
                    minimize(ans, shift_2);
                }
            }
        }
    }
    cout << ans << endl;
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