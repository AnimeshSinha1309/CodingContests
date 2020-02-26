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

vll get_rank(vll a) {
    vpl x(a.size());
    vll res(a.size());
    for (int i = 0; i < a.size(); i++)
        x[i] = {a[i], i};
    sort(x.begin(), x.end());
    for (ll i = 0, rank = 1; i < a.size(); i++) {
        if (i > 0 && x[i - 1].first != x[i].first)
            rank++;
        res[x[i].second] = rank;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    vll rank = get_rank(a);
    set<ll> temp_score(a.begin(), a.end());
    temp_score.insert(0);
    vll score(temp_score.begin(), temp_score.end());
    sort(a.begin(), a.end());
    mll dp(n + 1, vll(*max_element(a.begin(), a.end()) + 1, 1e15));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + 1;
        for (int j = 1; j <= rank[i - 1]; j++) {
            dp[i][j] =
                min(dp[i - 1][j], dp[i][j - 1] + score[j] - score[j - 1]);
        }
        if (rank[i - 1] > (i > 1 ? rank[i - 2] : 0))
            dp[i][rank[i - 1]]--;
    }
    cout << dp[n][0] << endl;
}