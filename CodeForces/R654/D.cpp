#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<int> vll;
typedef vector<vector<int>> mll;
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
        out << val;
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
        ll n, k;
        cin >> n >> k;
        mll mat(n, vll(n, 0));
        cout << ((k % n == 0) ? 0 : 2) << endl;
        int i = 0, j = 0;
        for (int l = 0; l < k; l++) {
            mat[i][j]++;
            i++, j++;
            if (i == n)
                i = 0;
            if (j == n)
                j = 0;
            if (mat[i][j] != 0)
                j++;
        }
        cout << mat;
    }
}