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
    ll n, m, k, a, b;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
        cin >> a >> b;
    for (int i = 0; i < k; i++)
        cin >> a >> b;
    // Outputs
    cout << (n - 1) + (m - 1) + (n - 1) * m + (m - 1) << endl;
    for (int i = 1; i < m; i++)
        cout << "L";
    for (int i = 1; i < n; i++)
        cout << "U";
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++)
            cout << (i % 2 == 0 ? "D" : "U");
        if (i != m - 1)
            cout << "R";
    }
    cout << endl;
}