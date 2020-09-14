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
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        // Take the inputs and convert format
        ll n;
        cin >> n;
        vpl a(n);
        ll cycle_time = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            a[i].second += a[i].first;
            cycle_time += a[i].first;
        }
        vpl b(n);
        for (int i = 0; i < n; i++)
            b[i].first = a[i].second, b[i].second = i;
        sort(b.begin(), b.end());
        // I can stay if cycle_time >= a[i].second
        ll lost_time = 0, prefix_time = 0;
        ll ans_remove = 0, ans_val = 0;
        priority_queue<pll> q;
        for (int i = 0; i < n; i++) {
            ll ans_temp = cycle_time + prefix_time - lost_time * 2;
            if (ans_temp > ans_val)
                ans_remove = i - q.size(), ans_val = ans_temp;
            else if (ans_temp == ans_val)
                minimize(ans_remove, i - (ll)q.size());
            prefix_time += a[i].first;
            q.emplace(a[i].second, a[i].first);
            while (!q.empty() && q.top().first > cycle_time - lost_time)
                lost_time += q.top().second, q.pop();
        }
        // Print the answers
        if (!q.empty())
            cout << "Case #" << test << ": " << n - (ll)q.size() << ' '
                 << "INDEFINITELY" << endl;
        else
            cout << "Case #" << test << ": " << ans_remove << ' ' << ans_val
                 << endl;
    }
}