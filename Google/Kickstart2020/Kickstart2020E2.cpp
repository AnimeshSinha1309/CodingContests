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
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        ll n, a, b, c;
        cin >> n >> a >> b >> c;
        cout << "Case #" << test << ": ";

        if (a + b - c > n || (a == 1 && b == 1 && n != 1)) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int i = a - c; i >= 1; i--) {
                cout << n - i << ' ';
            }
            for (int i = 0; i < n - (a + b - c) && a - c > 0; i++) {
                cout << 1 << ' ';
            }
            if (a == c && b == c) {
                cout << n << ' ';
                for (int i = 0; i < n - c; i++) {
                    cout << 1 << ' ';
                }
                for (int i = 0; i < c - 1; i++) {
                    cout << n << ' ';
                }
            } else {
                for (int i = 0; i < c; i++) {
                    cout << n << ' ';
                }
            }
            for (int i = 0; i < n - (a + b - c) && b - c > 0 && a - c <= 0;
                 i++) {
                cout << 1 << ' ';
            }
            for (int i = 1; i <= b - c; i++) {
                cout << n - i << ' ';
            }
            cout << endl;
        }
    }
}