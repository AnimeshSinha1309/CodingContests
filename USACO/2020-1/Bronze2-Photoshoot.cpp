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
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    ll n;
    cin >> n;
    vll b(n - 1);
    cin >> b;
    vll a(n);
    for (int i = 0; i < n; i++) {
        a[0] = i + 1;
        for (int j = 1; j < n; j++)
            a[j] = b[j - 1] - a[j - 1];
        bool is_permutation = true;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            if (a[i] != i + 1) {
                is_permutation = false;
                break;
            }
        if (is_permutation) {
            cout << i + 1 << " ";
            for (int j = 1, last = i + 1; j < n; j++) {
                last = b[j - 1] - last;
                if (j < n - 1)
                    cout << last << " ";
                else
                    cout << last;
            }
            break;
        }
    }
}