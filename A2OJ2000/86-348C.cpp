#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef vector<vpl> mpl;
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
    // Take the input
    ll n, m, q;
    cin >> n >> m >> q;
    vll a(n);
    mll is_in_set(n);
    cin >> n;
    mll s(m);
    vll big_set_id(m, -1);
    ll big_set_count = 0;
    for (int i = 0; i < m; i++) {
        ll k;
        cin >> k;
        s[i] = vll(k);
        cin >> s[i];
        if (k >= sqrt(n)) {
            big_set_id[i] = big_set_count++;
            for (auto el : s[i])
                is_in_set[el].push_back(big_set_id[i]);
        }
    }
    // Do the big set intersection computations
    mll intersections(big_set_count, vll(n, 0));
    for (int i = 0; i < m; i++) {
        for (auto el : s[i]) {
            for (auto big_set : is_in_set[el])
                intersections[el][i]++;
        }
    }
    // Start answering the queries
    vll values_el(n, 0), values_set(m, 0);
    for (int qi = 0; qi < q; qi++) {
        char type;
        cin >> type;
        if (type == '?') {
            ll k;
            cin >> k;
            k--;
        } else if (type == '+') {
            ll k, x;
            cin >> k >> x;
            k--;
            if (big_set_id[k] == -1) {
                for (auto el : s[k])
                    values_el[el] += x * s[k].size();
            }
            for (int i = 0; i < big_set_count; i++) {
                values_set[i] += intersections[i][k] * x;
            }
        }
    }
}