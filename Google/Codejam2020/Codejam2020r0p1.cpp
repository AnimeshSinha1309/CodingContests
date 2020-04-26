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
        ll n;
        cin >> n;
        mll mat(n, vll(n));
        cin >> mat;
        ll k = 0, r = 0, c = 0;
        vbl seen(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (seen[mat[i][j] - 1]) {
                    r++;
                    break;
                }
                seen[mat[i][j] - 1] = true;
            }
            seen.assign(n, false);
            for (int j = 0; j < n; j++) {
                if (seen[mat[j][i] - 1]) {
                    c++;
                    break;
                }
                seen[mat[j][i] - 1] = true;
            }
            seen.assign(n, false);
            k += mat[i][i];
        }
        cout << "Case #" << test << ": " << k << " " << r << " " << c << endl;
    }
}