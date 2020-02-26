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
    ll n, a, b;
    cin >> n >> a >> b;
    if (a * b >= 6 * n) {
        cout << a * b << endl << a << " " << b << endl;
        return 0;
    }
    bool swapped = a > b;
    if (a > b)
        swap(a, b);
    for (ll area = 6 * n;; area++) {
        for (ll l1 = a; l1 * b <= area && l1 * l1 <= area; l1++) {
            if (area % l1 == 0) {
                if (swapped)
                    l1 = area / l1;
                cout << area << endl << l1 << " " << area / l1 << endl;
                return 0;
            }
        }
    }
}