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
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vll a(n);
        cin >> a;
        vbl p(n);
        for (int i = 1; i < n - 1; i++)
            if (a[i - 1] < a[i] && a[i] > a[i + 1])
                p[i] = true;
        vll ans(n - k + 1, 0);
        int i = 0, j = 0;
        while (j < k)
            ans[0] += p[j], j++;
        while (j < n) {
            ans[i + 1] = ans[i] + p[j] - p[i];
            i++, j++;
        }
        for (int i = 0; i <= n - k; i++)
            ans[i] -= p[i] + p[i + k - 1];
        int l = 0;
        for (int i = 0; i <= n - k; i++)
            if (ans[l] < ans[i])
                l = i;
        cout << ans[l] + 1 << " " << l + 1 << endl;
    }
}