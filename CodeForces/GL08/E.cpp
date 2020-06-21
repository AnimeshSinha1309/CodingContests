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
    ll n;
    cin >> n;
    ll ans = max(n / 2 - 1, 0ll), cur = 0;
    vbl state(n, false);
    while (true) {
        // Break if done
        if (cur == ans) {
            cout << 0 << endl;
            break;
        }
        // Give the set
        ll a, b;
        for (a = n % 2; a < n && state[a]; a += 2)
            ;
        for (b = a + 2; b < n && state[b]; b += 2)
            ;
        cout << 2 << ' ' << a + 1 << ' ' << b + 1 << endl;
        if (!state[a])
            cur++;
        if (!state[b])
            cur++;
        state[a] = true;
        state[b] = true;
        // Get the response
        ll in;
        cin >> in;
        in--;
        if (in == -1)
            exit(0);
        if (state[in])
            cur--;
        if (state[(in + 1) % n])
            cur--;
        state[in] = false;
        state[(in + 1) % n] = false;
    }
}