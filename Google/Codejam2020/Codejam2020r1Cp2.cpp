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
        ll u;
        cin >> u;
        vpl p(26);
        for (int i = 0; i < 26; i++)
            p[i].second = i;
        for (int i = 0; i < (ll)1e4; i++) {
            ll m;
            string r;
            cin >> m >> r;
            for (auto ch : r)
                p[ch - 'A'].first++;
            p[r[0] - 'A'].first += 10;
        }
        sort(p.rbegin(), p.rend());
        string ans = "";
        ans += p[9].second + 'A';
        for (int i = 0; i < 9; i++) {
            ans += p[i].second + 'A';
        }
        cout << "Case #" << test << ": " << ans << endl;
    }
}