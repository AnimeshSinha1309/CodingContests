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
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll m;
        cin >> m;
        vll a(m);
        cin >> a;
        ll n = s.size();
        vll ans(m, -1);

        for (int iter = 0; iter < 26; iter++) {
            set<ll> pos_0;
            for (int i = 0; i < m; i++) {
                if (a[i] == 0)
                    pos_0.insert(i), a[i] = -1;
            }
            for (auto el : pos_0)
                ans[el] = iter;
            for (int i = 0; i < m; i++) {
                for (auto el : pos_0)
                    if (a[i] != -1)
                        a[i] -= abs(i - el);
            }
        }

        ll used = *max_element(ans.begin(), ans.end()) + 1;
        for (int i = 0; i < m; i++)
            ans[i] = used - ans[i] - 1;

        vll supply(26, 0);
        for (int i = 0; i < n; i++)
            supply[s[i] - 'a']++;
        vll demand(used, 0);
        for (int i = 0; i < m; i++)
            demand[ans[i]]++;

        vector<char> match(used, '0');
        for (int i = 0, j = 0; j < 26 && i < used; j++) {
            if (supply[j] >= demand[i]) {
                match[i++] = 'a' + j;
            }
        }
        for (auto el : ans)
            cout << match[el];
        cout << endl;
    }
}