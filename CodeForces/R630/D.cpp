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

ll test(mll mat) {
    mll dp(4, vll(4, 0));
    dp[0][1] = mat[0][0];
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            dp[i][j] = max(dp[i - 1][j] & mat[i - 1][j - 1],
                           dp[i][j - 1] & mat[i - 1][j - 1]);
    return dp[3][3];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll k;
    cin >> k;
    mll a = {{0b111111111111111111, k, 0},
             {0b100000000000000000, 0b111111111111111111, 0b011111111111111111},
             {0, 0b011111111111111111, 0b111111111111111111}};
    cout << 3 << " " << 3 << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}