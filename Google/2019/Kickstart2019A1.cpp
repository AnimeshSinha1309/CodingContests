// Accepted
// Tags: #Trivial

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        unsigned long n, p;
        cin >> n >> p;
        vector<long long> s(n);
        for (unsigned long i = 0; i < n; i++) cin >> s[i];
        sort(s.begin(), s.end());
        long long moving_diff = 0;
        for (unsigned long i = 0; i < p; i++) moving_diff += s[p - 1] - s[i];
        long long training_hours = moving_diff;
        for (unsigned long i = p; i < n; i++) {
            moving_diff += p * (s[i] - s[i - 1]);
            moving_diff -= s[i] - s[i - p];
            training_hours = (training_hours < moving_diff) ? training_hours : moving_diff;
        }
        cout << "Case #" << test << ": " << training_hours << endl;
    }
}