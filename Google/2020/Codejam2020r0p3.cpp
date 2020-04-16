#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;

struct Job {
    ll start = -1, end = -1;
    int index = -1;
    friend const bool operator<(const Job &a, const Job &b) {
        return a.start < b.start;
    }
};

int main() {
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
