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
        ll n, k;
        cin >> n >> k;
        k++;
        string s;
        cin >> s;
        vll ans = {0};
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                ans.push_back(0);
            else
                ans[ans.size() - 1]++;
        }
        if (ans.size() == 1) {
            cout << (n - 1) / k + 1 << endl;
            continue;
        }
        ll res = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (i == 0 || i == ans.size() - 1) {
                res += ans[i] / k;
            } else {
                res += (ans[i] + 1) / k - 1;
            }
        }
        cout << res << endl;
    }
}