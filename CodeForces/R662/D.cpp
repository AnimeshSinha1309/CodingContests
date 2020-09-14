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
    vector<vector<bool>> dp(n, vector<bool>(m, false));
    vector<vector<bool>> nx(n, vector<bool>(m, false));
    queue<pair<int, int>> q, r;
    cin >> mat;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if ((mat[i][j] == mat[i - 1][j]) && (mat[i][j] == mat[i][j - 1]) &&
                (mat[i][j] == mat[i + 1][j]) && (mat[i][j] == mat[i][j + 1])) {
                dp[i][j] = true;
                q.emplace(i, j);
            }
        }
    }
    ll ans = n * m;
    ll min_dim = min(n, m);
    for (int x = 1; x < min_dim - x; x++) {
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            nx[i][j] = false;
            if (dp[i][j]) {
                ans++;
                if ((dp[i - 1][j] && dp[i][j - 1] && dp[i + 1][j] &&
                     dp[i][j + 1])) {
                    nx[i][j] = true;
                    r.emplace(i, j);
                }
            }
        }
        swap(dp, nx);
        swap(q, r);
    }
    cout << ans << endl;
}