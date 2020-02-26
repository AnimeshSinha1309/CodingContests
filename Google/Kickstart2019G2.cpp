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

#define BIT_SIZE 50

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        ll n, m;
        cin >> n >> m;
        vll a(n);
        cin >> a;
        ll sum = accumulate(a.begin(), a.end(), 0ll);
        vll bit_count(BIT_SIZE), bit_diff(BIT_SIZE), bit_defer(BIT_SIZE);
        for (int i = 0; i < n; i++) {
            for (int j = BIT_SIZE- 1; j >= 0; j--) {
                if ((a[i] & (1ll << j)) != 1) bit_count[j]++;
            }
        }
        for (int j = BIT_SIZE - 1; j >= 0; j--)
            bit_diff[j] = (1ll << j) * (n - 2 * bit_count[j]);
        for (int j = 1; j < BIT_SIZE; j++) {
            bit_defer[j] = min(0ll, bit_diff[j - 1]) + bit_defer[j - 1];
        }
        ll k = 0;
        for (int j = BIT_SIZE - 1; j >= 0; j--) {
            if (bit_diff[j] <= 0 || sum + bit_defer[j]) {
                sum += bit_diff[j];
            }
        }
        cout << "Case #" << test << ": " << ans << endl;
    }
}