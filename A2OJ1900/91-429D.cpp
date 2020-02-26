#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef vector<long long> vll;
typedef vector<pair<long long, long long>> vpl;

double closest_pair(const vpl &pt, int n) {
    // Code copied from vivace_jr:
    // https://codeforces.com/contest/429/submission/57180950
    double best = FLT_MAX;
    set<pll> box;
    box.insert(pt[0]);
    int left = 0;
    for (int i = 1; i < n; ++i) {
        while (left < i && pt[i].second - pt[left].second > sqrt(best))
            box.erase(pt[left++]);
        ll cnt = 0;
        for (auto it = box.lower_bound(
                 {pt[i].first - sqrt(best), pt[i].second - sqrt(best)});
             it != box.end() && pt[i].first + sqrt(best) >= it->first; it++) {
            cnt++;
            best = min(best, (pow(pt[i].first - it->first, 2.0) +
                              pow(pt[i].second - it->second, 2.0)));
        }
        box.insert(pt[i]);
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];
    vpl points(n);
    for (int i = 0; i < n; i++)
        points[i] = {a[i], i};
    cout << ((ll)closest_pair(points, n)) << endl;
    return 0;
}