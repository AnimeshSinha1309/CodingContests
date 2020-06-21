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

bool check(vll &a, ll val, ll k) {
    ll n = a.size();
    int to_even = 0, to_odd = 0, i = 0;
    bool ready = false;
    // Assume it's even positions
    for (i = 0, ready = false; i < n; i++) {
        if (a[i] <= val && ready)
            ready = false, to_even++;
        else
            ready = true;
    }
    if (to_even * 2 + (ready ? 1 : 0) >= k)
        return true;
    // Assume it's odd positions
    for (i = 0, ready = true; i < n; i++) {
        if (a[i] <= val && ready)
            ready = false, to_odd++;
        else
            ready = true;
    }
    if (to_odd * 2 - 1 + (ready ? 1 : 0) >= k)
        return true;
    // Didn't work
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vll a(n);
    cin >> a;
    ll result = 0;
    for (ll top = 1e9 + 10, bot = 0, mid = bot + (top - bot) / 2; bot <= top;
         mid = bot + (top - bot) / 2) {
        if (check(a, mid, k) && !check(a, mid - 1, k)) {
            result = mid;
            break;
        }
        (check(a, mid, k)) ? (top = mid - 1) : (bot = mid + 1);
    }
    cout << result << endl;
}