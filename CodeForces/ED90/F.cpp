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

ll n;
vll a, b;

bool check(ll start) {
    ll prev = start;
    for (int i = 0; i < n; i++) {
        if (a[i] - prev > b[i])
            return 1;
        prev = b[i] - max(a[i] - prev, 0ll);
    }
    if (prev + start < a[0])
        return -1;
    else
        return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        a = vll(n), b = vll(n);
        cin >> a >> b;
        ll result = -1;
        for (ll top = b[n - 1], bot = 0, mid = bot + (top - bot) / 2;
             bot <= top; mid = bot + (top - bot) / 2) {
            bool res = check(mid);
            if (res == 0) {
                result = mid;
                break;
            }
            (res == -1) ? (top = mid - 1) : (bot = mid + 1);
        }
        if (result != -1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}