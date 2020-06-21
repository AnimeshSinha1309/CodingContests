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
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n == 1) {
            cout << "FastestFinger" << endl;
        } else if (n == 2) {
            cout << "Ashishgup" << endl;
        } else if (n % 2 == 1) {
            cout << "Ashishgup" << endl;
        } else {
            ll n_ = n;
            while (n_ % 2 == 0)
                n_ /= 2;
            ll odd_factors = n_ > 1 ? 1 : 0;
            for (int i = 2; i <= sqrt(n_); i++) {
                if (n_ % i == 0)
                    odd_factors += 2;
            }
            if ((odd_factors >= 2) || (odd_factors == 1 && n % 4 == 0))
                cout << "Ashishgup" << endl;
            else
                cout << "FastestFinger" << endl;
        }
    }
}