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

inline ll sq(ll defn) {
    return defn * defn;
}

ll solve(const vll &vr, const vll &vg, const vll &vb) {
    ll ans = INT64_MAX;
    ll nr = vr.size(), ng = vg.size(), nb = vb.size();
    for (int i = 0, j = 0, k = 0; j < ng; j++) {
        // Get the closest red
        while (i < nr - 1 && vr[i + 1] < vg[j])
            i++;
        // Get the closest blue
        while (k < nb && vb[k] < vg[j])
            k++;
        if (i < nr && k < nb && vr[i] <= vg[j] && vg[j] <= vb[k]) {
            minimize(ans,
                     sq(vr[i] - vg[j]) + sq(vg[j] - vb[k]) + sq(vb[k] - vr[i]));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll nr, ng, nb;
        cin >> nr >> ng >> nb;
        vll vr(nr), vg(ng), vb(nb);
        cin >> vr >> vg >> vb;
        sort(vr.begin(), vr.end());
        sort(vg.begin(), vg.end());
        sort(vb.begin(), vb.end());
        ll ans = INT64_MAX;
        minimize(ans, solve(vr, vg, vb));
        minimize(ans, solve(vr, vb, vg));
        minimize(ans, solve(vg, vr, vb));
        minimize(ans, solve(vg, vb, vr));
        minimize(ans, solve(vb, vr, vg));
        minimize(ans, solve(vb, vg, vr));
        cout << ans << endl;
    }
}