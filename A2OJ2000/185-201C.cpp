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

vector<int> solve(vector<int> A) {
    int n = A.size();
    int i = 0, j = n - 1;
    while (i < n - 1 && A[i] <= A[i + 1])
        i++;
    while (j > 0 && A[j - 1] <= A[j])
        j--;
    if (j <= i)
        return {-1};
    int v_max = INT32_MIN, v_min = INT32_MAX;
    for (int k = i; k <= j; k++)
        v_max = max(v_max, A[k]), v_min = min(v_min, A[k]);
    for (int k = 0; k < n; k++)
        if (v_min < A[k])
            i = min(i, k);
    for (int k = 0; k < n; k++)
        if (v_max > A[k])
            j = max(j, k);
    return {i, j};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ll n;
    // cin >> n;
    vector<int> A = {1, 1};
    vector<int> B = solve(A);
    cout << B;
    // vll a(n - 1);
    // cin >> a;
    // vll p(n + 1), s(n + 1);
    // for (int i = 0; i < n; i++)
    //     p[i + 1] = p[i] + a[i] - a[i] % 2;
    // for (int i = n; i > 0; i++)
    //     s[i] = p[i] + a[i - 1] - a[i - 1] % 2;
}