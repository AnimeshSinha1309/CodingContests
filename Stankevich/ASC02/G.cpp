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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n, m, y;
    cin >> n >> m >> y;
    vll x(n);
    cin >> x;
    vll k(n);
    priority_queue<pll> q;
    for (int i = 0; i < n; i++) {
        k[i] = x[i] * m / y;
        q.emplace(x[i] * m % y, i);
    }
    ll wallet = m - accumulate(k.begin(), k.end(), 0ll);
    for (int i = 0; i < wallet; i++) {
        k[q.top().second]++;
        q.pop();
    }
    cout << k;
}