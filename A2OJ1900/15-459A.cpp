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
ostream &operator<<(ostream &out, bool &val) {
    if (val)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pll a, b, c, d;
    cin >> a.first >> a.second >> b.first >> b.second;
    if (a.first == b.first) {
        c.second = a.second;
        d.second = b.second;
        c.first = a.first + abs(a.second - b.second);
        d.first = b.first + abs(a.second - b.second);
    } else if (a.second == b.second) {
        c.first = a.first;
        d.first = b.first;
        c.second = a.second + abs(a.first - b.first);
        d.second = b.second + abs(a.first - b.first);
    } else {
        if (abs(a.first - b.first) != abs(a.second - b.second)) {
            cout << "-1" << endl;
            return 0;
        }
        c.first = a.first;
        c.second = b.second;
        d.first = b.first;
        d.second = a.second;
    }
    cout << c.first << " " << c.second << " " << d.first << " " << d.second
         << endl;
}