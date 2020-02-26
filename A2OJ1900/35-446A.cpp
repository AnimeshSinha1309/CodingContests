#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n; cin >> n;
    vector<long long> list((unsigned)n);
    for (auto &item : list) cin >> item;
    vector<long long> dp1((unsigned)n, 1), dp2((unsigned)n, 1);
    for (int i = 1; i < n; i++) {
        if (list[i] > list[i-1]) dp1[i] = dp1[i-1] + 1;
        if (i > 1 && list[i] > list[i-2] + 1) dp2[i] = max(dp2[i], dp1[i-2] + 2);
        if (list[i] > list[i-1]) dp2[i] = max(dp2[i], dp2[i-1] + 1);
    } cout << min(max(*max_element(dp1.begin(), dp1.end()) + 1, *max_element(dp2.begin(), dp2.end())), n) << endl;
}