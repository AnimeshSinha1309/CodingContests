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

#define ce(x, y) ((x + y - 1) / (y))

bool check(const vll &m, ll difficulty, ll sessions) {
    if (difficulty == 0)
        return false;
    int n = m.size();
    ll required = 0;
    for (int i = 1; i < n; i++) {
        required += max(ce(m[i] - m[i - 1], difficulty) - 1, 0ll);
    }
    return required <= sessions;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        ll n, k;
        cin >> n >> k;
        vll m(n);
        cin >> m;
        ll result = 0;
        for (ll top = 1e9, bot = 0, mid = bot + (top - bot) / 2; bot <= top;
             mid = bot + (top - bot) / 2) {
            if (check(m, mid, k) && !check(m, mid - 1, k)) {
                result = mid;
                break;
            }
            (check(m, mid, k)) ? (top = mid - 1) : (bot = mid + 1);
        }
        cout << "Case #" << test << ": " << result << endl;
    }
}