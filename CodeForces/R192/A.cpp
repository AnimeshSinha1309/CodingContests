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
    vector<string> mat(n);
    cin >> mat;
    vector<int> row(n, n), col(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 'E')
                continue;
            minimize(row[i], j);
            minimize(col[j], i);
        }
    }
    if (*max_element(row.begin(), row.end()) < n) {
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " " << row[i] + 1 << endl;
        }
    } else if (*max_element(col.begin(), col.end()) < n) {
        for (int i = 0; i < n; i++) {
            cout << col[i] + 1 << " " << i + 1 << endl;
        }
    } else {
        cout << "-1" << endl;
    }
}