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

template<typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
    ll n = vec.size();
    for (int i = 0; i < n; i++)
        in >> vec[i];
    return in;
}

template<typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    out << endl;
    return out;
}

bool check(vll &x, ll d, ll start) {
    ll days = start;
    for (long long i : x) {
        if (days % i == 0) continue;
        else days = days + i - (days % i);
    }
    return days <= d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        ll n, d; cin >> n >> d;
        vll x(n); cin >> x;
        ll result = 0;
        for (ll top = d, bot = 0, mid = (top + bot) / 2; bot <= top; mid = (bot + top) / 2) {
            if (check(x, d, mid) && !check(x, d, mid + 1)) {
                result = mid;
                break;
            }
            (!check(x, d, mid)) ? (top = mid - 1) : (bot = mid + 1);
        }
        cout << "Case #" << test << ": " << result << endl;
    }
}