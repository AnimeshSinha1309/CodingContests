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
    const long long n = 100;
    struct Ends {
        int RED_RED = 0, RED_BLUE = 0, BLUE_BLUE = 0, RED_NONE = 0,
            BLUE_NONE = 0, NONE = 0;
    };
    vector<Ends> dp(n);
    for (int size = 0; size < n; size++) {
        for (int split = 1; split <= n; split++) {
            maximize(dp[size].RED_RED,
                     dp[split - 1].BLUE_BLUE + dp[n - split].BLUE_BLUE);
        }
    }
}
