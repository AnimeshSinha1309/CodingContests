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

struct Job {
    ll start = -1, end = -1;
    int index = -1;

    friend const bool operator<(const Job &a, const Job &b) {
        return a.start < b.start;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        ll n;
        cin >> n;
        vector<Job> acts(n);
        for (int i = 0; i < n; i++)
            cin >> acts[i].start >> acts[i].end, acts[i].index = i;
        sort(acts.begin(), acts.end());
        string ans(n, 'A');
        ll free_c = -1, free_j = -1;
        for (int i = 0; i < n; i++) {
            if (free_c <= acts[i].start) {
                ans[acts[i].index] = 'C', free_c = acts[i].end;
            } else if (free_j <= acts[i].start) {
                ans[acts[i].index] = 'J', free_j = acts[i].end;
            } else {
                ans = "IMPOSSIBLE";
                break;
            }
        }
        cout << "Case #" << test << ": " << ans << endl;
    }
}