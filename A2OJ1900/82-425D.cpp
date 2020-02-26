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
ostream &operator<<(ostream &out, bool &val) {
    if (val)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    mll x(100001), y(100001);
    unordered_set<ll> points;
    ll n;
    cin >> n;
    vpl pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
        points.insert(pts[i].first * 200000 + pts[i].second);
        x[pts[i].first].push_back(pts[i].second);
        y[pts[i].second].push_back(pts[i].first);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (x[pts[i].first].size() < y[pts[i].second].size()) {
            for (ll y_val : x[pts[i].first]) {
                if (y_val <= pts[i].second)
                    continue;
                ll x_val = pts[i].first + (y_val - pts[i].second);
                if (x_val > 100000)
                    continue;
                if (points.find(x_val * 200000 + pts[i].second) !=
                        points.end() &&
                    points.find(x_val * 200000 + y_val) != points.end())
                    ans++;
            }
        } else {
            for (ll x_val : y[pts[i].second]) {
                if (x_val <= pts[i].first)
                    continue;
                ll y_val = pts[i].second + (x_val - pts[i].first);
                if (y_val > 100000)
                    continue;
                if (points.find(pts[i].first * 200000 + y_val) !=
                        points.end() &&
                    points.find(x_val * 200000 + y_val) != points.end())
                    ans++;
            }
        }
    }
    cout << ans << endl;
}