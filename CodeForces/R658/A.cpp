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

void solve() {
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vbl s(n), t(n);
    for (int i = 0; i < n; i++)
        s[i] = a[i] == '1', t[i] = b[i] == '1';
    int ptr1 = 0, ptr2 = n - 1;
    bool front = false, flipped = false;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        int ptr = front ? ptr1 : ptr2;
        if (flipped ? s[ptr] == t[i] : s[ptr] != t[i]) {
            if (s[ptr1 + ptr2 - ptr] != s[ptr]) {
                ans.push_back(1);
                s[ptr1 + ptr2 - ptr] = !s[ptr1 + ptr2 - ptr];
            }
            ans.push_back(ptr2 - ptr1 + 1);
            front = !front;
            flipped = !flipped;
        }
        front ? ptr1++ : ptr2--;
    }
    cout << ans.size() << ' ' << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}