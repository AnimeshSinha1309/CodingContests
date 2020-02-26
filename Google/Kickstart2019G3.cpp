#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        // Take the inputs
        int n, h;
        cin >> n >> h;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        // Perform DP-SOS to find happiness of A and B
        vector<long long> dp_a(1 << n), dp_b(1 << n);
        for (int i = 0; i < n; i++)
            dp_a[1 << i] = a[i], dp_b[1 << i] = b[i];
        for (int i = 0; i < n; ++i)
            for (int mask = 0; mask < (1 << n); ++mask)
                if (mask & (1 << i)) {
                    dp_a[mask] += dp_a[mask ^ (1 << i)];
                    dp_b[mask] += dp_b[mask ^ (1 << i)];
                }
        // Find for how many subsets of each subset is B happy
        const long long ones = (1 << n) - 1;
        vector<long long> ans_b(1 << n);
        for (int i = 0; i < (1 << n); i++)
            ans_b[ones ^ i] = (dp_b[i] >= h) ? 1 : 0;
        for (int i = 0; i < n; ++i)
            for (int mask = 0; mask < (1 << n); ++mask)
                if (mask & (1 << i))
                    ans_b[mask] += ans_b[mask ^ (1 << i)];
        // Loop over all these subsets and count
        long long ans_a = 0;
        for (int i = 0; i < (1 << n); i++)
            if (dp_a[i] >= h)
                ans_a += ans_b[i];
        cout << "Case #" << test << ": " << ans_a << endl;
    }
}