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

ll next_x(ll x) {
    return (x * 37 + 10007) % 1000000007;
}
void init(vll &a, vll &b, ll n, ll x, ll d) {
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    for (int i = 0; i < n; i++)
        swap(a[i], a[next_x(x) % (i + 1)]);
    for (int i = 0; i < n; i++)
        b[i] = i < d ? 1 : 0;
    for (int i = 0; i < n; i++)
        swap(b[i], b[next_x(x) % (i + 1)]);
}

template <typename T>
vector<size_t> argsort(const vector<T> &v) {
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    stable_sort(idx.begin(), idx.end(),
                [&v](size_t i1, size_t i2) { return v[i1] < v[i2]; });
    return idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, x, d;
    cin >> n >> x >> d;
    vll a(n), b(n);
    init(a, b, n, x, d);
    vll c(n, 0);
    if (d > 1000) {
    } else {
        for (int i = 0; i < n; i++) {
            if (b[i] == 0)
                continue;
            for (int j = 0; j + i < n; j++)
                maximize(c[i + j], a[j]);
        }
    }
}