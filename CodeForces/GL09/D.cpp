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
        vll c(n + 1, 0);
        for (int i = 0; i < n; i++)
            if (a[i] < n)
                c[a[i]]++;
        vll ans;
        ans.reserve(2 * n);
        ll mex = 0;

        while (c[mex] > 0)
            mex++;
        while (true) {
            if (mex < n) {
                ans.push_back(mex);
                c[a[mex]]--;
                c[mex]++;
                if (c[a[mex]] == 0 && a[mex] < mex) {
                    swap(mex, a[mex]);
                } else {
                    a[mex] = mex;
                }
                while (c[mex] > 0)
                    mex++;
            } else {
                ll min_pos = -1;
                for (int i = 0; i < n; i++) {
                    if (a[i] != i) {
                        if (min_pos == -1 || a[min_pos] > a[i])
                            min_pos = i;
                    }
                }
                if (min_pos == -1)
                    break;
                ans.push_back(min_pos);
                c[a[min_pos]]--;
                if (c[a[min_pos]] == 0)
                    mex = a[min_pos];
                a[min_pos] = n;
            }
        }
        for (auto &el : ans)
            el++;
        cout << ans.size() << endl << ans;
    }
}