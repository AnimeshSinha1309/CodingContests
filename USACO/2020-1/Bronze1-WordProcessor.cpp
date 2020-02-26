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
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    ll remaining_space = k;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bool start_of_line = remaining_space == k;
        remaining_space -= s.size();
        if (remaining_space < 0)
            cout << "\n" << s, remaining_space = k - s.size();
        else
            cout << (start_of_line ? "" : " ") << s;
    }
}