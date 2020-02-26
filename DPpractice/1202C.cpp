#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<pair<long long, long long>> vpl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        // Taking the input and simulating the original walk
        string s;
        cin >> s;
        ll n = s.size();
        vpl positions(n + 1, {0, 0});
        for (int i = 1; i <= n; i++) {
            switch (s[i - 1]) {
                case 'W':
                    positions[i].first = positions[i - 1].first;
                    positions[i].second = positions[i - 1].second + 1;
                    break;
                case 'S':
                    positions[i].first = positions[i - 1].first;
                    positions[i].second = positions[i - 1].second - 1;
                    break;
                case 'A':
                    positions[i].first = positions[i - 1].first - 1;
                    positions[i].second = positions[i - 1].second;
                    break;
                case 'D':
                    positions[i].first = positions[i - 1].first + 1;
                    positions[i].second = positions[i - 1].second;
                    break;
            }
        }
        // Computing Coordinate range in Prefix and Suffix
        vll prefix_min_x(n + 1, INT32_MAX), prefix_min_y(n + 1, INT32_MAX),
            suffix_min_x(n + 1, INT32_MAX), suffix_min_y(n + 1, INT32_MAX),
            prefix_max_x(n + 1, INT32_MIN), prefix_max_y(n + 1, INT32_MIN),
            suffix_max_x(n + 1, INT32_MIN), suffix_max_y(n + 1, INT32_MIN);
        prefix_max_x[0] = prefix_min_x[0] = positions[0].first;
        prefix_max_y[0] = prefix_min_y[0] = positions[0].second;
        suffix_max_x[n] = suffix_min_x[n] = positions[n].first;
        suffix_max_y[n] = suffix_min_y[n] = positions[n].second;
        for (int i = 1; i <= n; i++) {
            prefix_max_x[i] = max(prefix_max_x[i - 1], positions[i].first);
            prefix_min_x[i] = min(prefix_min_x[i - 1], positions[i].first);
            prefix_max_y[i] = max(prefix_max_y[i - 1], positions[i].second);
            prefix_min_y[i] = min(prefix_min_y[i - 1], positions[i].second);
        }
        for (int i = n - 1; i >= 0; i--) {
            suffix_max_x[i] = max(suffix_max_x[i + 1], positions[i].first);
            suffix_min_x[i] = min(suffix_min_x[i + 1], positions[i].first);
            suffix_max_y[i] = max(suffix_max_y[i + 1], positions[i].second);
            suffix_min_y[i] = min(suffix_min_y[i + 1], positions[i].second);
        }
        // Applying the new character here
        ll max_area = INT64_MAX;
        for (int i = 0; i <= n; i++) {
            max_area =
                min(max_area, (max(prefix_max_x[i], suffix_max_x[i] + 1) -
                               min(prefix_min_x[i], suffix_min_x[i] + 1) + 1) *
                                  (max(prefix_max_y[i], suffix_max_y[i]) -
                                   min(prefix_min_y[i], suffix_min_y[i]) + 1));
            max_area =
                min(max_area, (max(prefix_max_x[i], suffix_max_x[i] - 1) -
                               min(prefix_min_x[i], suffix_min_x[i] - 1) + 1) *
                                  (max(prefix_max_y[i], suffix_max_y[i]) -
                                   min(prefix_min_y[i], suffix_min_y[i]) + 1));
            max_area = min(max_area,
                           (max(prefix_max_x[i], suffix_max_x[i]) -
                            min(prefix_min_x[i], suffix_min_x[i]) + 1) *
                               (max(prefix_max_y[i], suffix_max_y[i] + 1) -
                                min(prefix_min_y[i], suffix_min_y[i] + 1) + 1));
            max_area = min(max_area,
                           (max(prefix_max_x[i], suffix_max_x[i]) -
                            min(prefix_min_x[i], suffix_min_x[i]) + 1) *
                               (max(prefix_max_y[i], suffix_max_y[i] - 1) -
                                min(prefix_min_y[i], suffix_min_y[i] - 1) + 1));
        }
        // Printing out the result
        cout << max_area << endl;
    }
}