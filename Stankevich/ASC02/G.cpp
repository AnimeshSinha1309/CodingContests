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
    ll n, m, y;
    cin >> n >> m >> y;
    vll x(n);
    cin >> x;
    mll dp(n + 1, vll(2 * y + 1, INT32_MAX));
    enum Direction { UP, DOWN, UNK };
    vector<vector<Direction>> prev(n + 1, vector<Direction>(2 * y + 3, UNK));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        ll up = x[i] * m % y, dn = y - up;
        for (int j = -y; j <= y; j++) {
            if (abs(j + up) <= y && dp[i + 1][j + up + y] > dp[i][j + y] + up) {
                dp[i + 1][j + up + y] = dp[i][j + y] + up;
                prev[i + 1][j + y] = DOWN;
            }
            if (abs(j - dn) <= y && dp[i + 1][j - dn + y] > dp[i][j + y] + dn) {
                dp[i + 1][j + dn + y] = dp[i][j + y] + dn;
                prev[i + 1][j + y] = UP;
            }
        }
    }
    vector<Direction> round(n);
    for (int i = n, j = 0; i > 0; i--) {
        if (prev[i][j] == UP) {
            round[i - 1] = DOWN;
            j--;
        }
        if (prev[i][j] = UP) {
            round[i - 1] = UP;
            j++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (round[i] == UP)
            cout << (int)floor(x[i] * m / y) << " ";
        if (round[i] == DOWN)
            cout << (int)ceil(x[i] * m / y) << " ";
    }
    cout << endl;
}
