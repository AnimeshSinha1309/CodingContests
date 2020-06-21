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
    // Input
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    // Check if fails
    ll count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            count++;
        if (t[i] == '0')
            count--;
    }
    if (count != 0) {
        cout << -1 << endl;
        exit(0);
    }
    // In the string
    ll running = 0, top = 0;
    ll seq_0 = 0, seq_1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            if (s[i] == '0') {
                seq_0++;
                seq_1 = max(seq_1 - 1, 0ll);
            } else {
                seq_1++;
                seq_0 = max(seq_0 - 1, 0ll);
            }
            top = max(top, seq_0 + seq_1);
        }
    }
    // Output
    cout << top << endl;
}