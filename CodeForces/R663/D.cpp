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
    vector<string> mat(n);
    cin >> mat;
    if (n == 1) {
        cout << 0 << endl;
    } else if (n == 2 || n == 3) {
        ll ans = INT64_MAX;
        for (int mask = 0; mask < (1 << (2 * n)); mask++) {
            // Check mask is valid
            if (n == 2) {
                int count =
                    ((mask & (1 << 0)) ? 1 : 0) + ((mask & (1 << 1)) ? 1 : 0) +
                    ((mask & (1 << 2)) ? 1 : 0) + ((mask & (1 << 3)) ? 1 : 0);
                if (count % 2 == 0)
                    continue;
            } else if (n == 3) {
                int count_1 =
                    ((mask & (1 << 0)) ? 1 : 0) + ((mask & (1 << 1)) ? 1 : 0) +
                    ((mask & (1 << 3)) ? 1 : 0) + ((mask & (1 << 4)) ? 1 : 0);
                int count_2 =
                    ((mask & (1 << 1)) ? 1 : 0) + ((mask & (1 << 2)) ? 1 : 0) +
                    ((mask & (1 << 4)) ? 1 : 0) + ((mask & (1 << 5)) ? 1 : 0);
                if (count_1 % 2 == 0)
                    continue;
                if (count_2 % 2 == 0)
                    continue;
            }
            // Compute ans
            ll temp_ans = 0;
            for (int j = 0; j < m; j++) {
                ll sub_ans = 0;
                for (int i = 0; i < n; i++) {
                    int pos = mask & (1 << ((j & 1) * n + i));
                    if ((pos == 0 && mat[i][j] == '1') ||
                        (pos != 0 && mat[i][j] == '0'))
                        sub_ans++;
                }
                temp_ans += min(sub_ans, n - sub_ans);
            }
            minimize(ans, temp_ans);
        }
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}