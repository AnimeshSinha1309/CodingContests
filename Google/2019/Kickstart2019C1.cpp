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

#define NEXT_N(r, c) (next_n[r].count(c) ? next_n[r][c] : r - 1)
#define NEXT_S(r, c) (next_s[r].count(c) ? next_s[r][c] : r + 1)
#define NEXT_E(r, c) (next_e[r].count(c) ? next_e[r][c] : c + 1)
#define NEXT_W(r, c) (next_w[r].count(c) ? next_w[r][c] : c - 1)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        ll n, r, c, sr, sc;
        cin >> n >> r >> c >> sr >> sc;
        string s;
        cin >> s;
        vector<map<ll, ll>> next_n(r + 2), next_s(r + 2), next_e(r + 2),
            next_w(r + 2);
        ll row = sr, col = sc;
        for (int i = 0; i < n; i++) {
            next_n[NEXT_S(row, col)][col] = NEXT_N(row, col);
            next_s[NEXT_N(row, col)][col] = NEXT_S(row, col);
            next_e[row][NEXT_W(row, col)] = NEXT_E(row, col);
            next_w[row][NEXT_E(row, col)] = NEXT_W(row, col);
            // Slide when on the block
            if (s[i] == 'N')
                row = NEXT_N(row, col);
            if (s[i] == 'S')
                row = NEXT_S(row, col);
            if (s[i] == 'E')
                col = NEXT_E(row, col);
            if (s[i] == 'W')
                col = NEXT_W(row, col);
        }
        cout << "Case #" << test << ": " << row << " " << col << endl;
    }
}
