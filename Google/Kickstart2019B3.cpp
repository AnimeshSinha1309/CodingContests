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

bool check(const vll &a, int k, int req) {
    if (req <= 0)
        return true;
    if (req > a.size())
        return false;
    ll n = a.size();
    vll f(1e5 + 1, 0);
    ll ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        ans++;
        f[a[i]]++;
        while (f[a[i]] > k) {
            f[a[j++]]--;
            ans--;
        }
        if (ans >= req)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        ll n, s;
        cin >> n >> s;
        vll a(n);
        cin >> a;
        ll result = 0;
        for (ll top = n, bot = 0, mid = bot + (top - bot) / 2; bot <= top;
             mid = bot + (top - bot) / 2) {
            if (check(a, s, mid) && !check(a, s, mid + 1)) {
                result = mid;
                break;
            }
            (check(a, s, mid)) ? (bot = mid + 1) : (top = mid - 1);
        }
        cout << "Case #" << test << ": " << result << endl;
    }
}