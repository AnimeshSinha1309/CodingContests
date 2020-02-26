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
#define sz(x) (int)x.size()
const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vll a(n);
    for (auto &x : a)
        cin >> x;
    ll m;
    cin >> m;
    // Generate all the permutation groups
    mll cycles;
    vbl visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        vll group;
        for (int j = i; !visited[j]; j = a[j] - 1) {
            group.push_back(j + 1);
            visited[j] = true;
        }
        cycles.push_back(group);
    }
    ll delta = n - sz(cycles) - m;
    // If the count needs to be increased
    if (delta < 0) {
        cout << -delta << endl;
        for (int i = 1; i <= abs(delta); i++) {
            cout << *min_element(cycles[0].begin(), cycles[0].end()) << " "
                 << *min_element(cycles[i].begin(), cycles[i].end()) << " ";
        }
    }
    // If the count needs to be increased
    else if (delta >= 0) {
        cout << delta << endl;
        for (int i = 1; i <= delta; i++) {
            // Find the Group and the Pair to be broken
            int group = -1;
            pll min_value = {1e15, 1e15};
            for (int j = 0; j < sz(cycles); j++) {
                if (sz(cycles[j]) < 2)
                    continue;
                pll cur_value = {1e15, 1e15};
                for (auto el : cycles[j]) {
                    if (el < cur_value.first) {
                        cur_value.second = cur_value.first;
                        cur_value.first = el;
                    } else if (el < cur_value.second) {
                        cur_value.second = el;
                    }
                }
                if (cur_value < min_value) {
                    group = j;
                    min_value = cur_value;
                }
            }
            cout << min_value.first << " " << min_value.second << " ";
            // Actually break the group up
            vll group_1, group_2;
            bool choice = false;
            for (int j = 0; j < sz(cycles[group]); j++) {
                if (!choice)
                    group_1.push_back(cycles[group][j]);
                else
                    group_2.push_back(cycles[group][j]);
                if (cycles[group][j] == min_value.first ||
                    cycles[group][j] == min_value.second) {
                    choice = !choice;
                }
            }
            cycles[group] = group_1;
            cycles.push_back(group_2);
        }
    }
    cout << endl;
}