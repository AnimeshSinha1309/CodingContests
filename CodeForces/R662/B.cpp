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
    ll n;
    cin >> n;
    vll a(1e5 + 10, 0);
    vll f(1e5 + 10, 0);
    f[0] = n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[temp]++;
        f[a[temp]]++;
    }
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char ch;
        int temp;
        cin >> ch >> temp;
        if (ch == '+') {
            a[temp]++;
            f[a[temp]]++;
        } else {
            f[a[temp]]--;
            a[temp]--;
        }

        cout << (((f[8] >= 1) || (f[4] >= 1 && f[2] >= 3) ||
                  (f[6] >= 1 && f[2] >= 2) || (f[4] >= 2))
                     ? "YES"
                     : "NO")
             << endl;
    }
}