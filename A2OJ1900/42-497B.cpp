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
    ll n, s, l;
    cin >> n >> s >> l;
    vll a(n);
    cin >> a;
    deque<ll> minima, maxima;
    vll dp_answer(n), dp_free(n);
    for (int i = 0, j = -1; i <= n; i++) {
        // 
        if (abs(a[i] - a[minima.front()]) > s ||
            abs(a[i] - a[maxima.front()]) > s) {
            if (dp_free[i] > l)
        }
        // Maintain the Minima and Maxima of current range
        while (!minima.empty() && a[minima.back()] >= a[i])
            minima.pop_back();
        while (!maxima.empty() && a[maxima.back()] <= a[i])
            minima.pop_back();
        minima.push_back(i);
        maxima.push_back(i);
    }
    cout << dp_answer[n - 1] << endl;
}