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
        vll a(n);
        cin >> a;
        vll negative, positive;
        negative.reserve(n);
        positive.reserve(n);
        for (int i = 0; i < n; i++) {
            if (a[i] < 0)
                negative.push_back(a[i]);
            else
                positive.push_back(a[i]);
        }
        sort(a.rbegin(), a.rend());
        sort(positive.rbegin(), positive.rend());
        sort(negative.begin(), negative.end());
        ll ans = a[0] * a[1] * a[2] * a[3] * a[4];
        if (positive.size() >= 1 && negative.size() >= 4) {
            ans = max(ans, positive[0] * negative[0] * negative[1] *
                               negative[2] * negative[3]);
        }
        if (positive.size() >= 3 && negative.size() >= 2) {
            ans = max(ans, positive[0] * positive[1] * positive[2] *
                               negative[0] * negative[1]);
        }
        if (positive.size() >= 5) {
            ans = max(ans, positive[0] * positive[1] * positive[2] *
                               positive[3] * positive[4]);
        }
        cout << ans << endl;
    }
}