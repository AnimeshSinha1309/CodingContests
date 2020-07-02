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
        string s;
        cin >> s;
        ll n_0 = 0, n_1 = 0, n_x = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0')
                break;
            n_0++;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '1')
                break;
            n_1++;
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1' && s[i + 1] == '0')
                n_x++;
        }
        for (int i = 0; i < n_0; i++)
            cout << '0';
        if (0 < n_x)
            cout << '0';
        for (int i = 0; i < n_1; i++)
            cout << '1';
        cout << endl;
    }
}