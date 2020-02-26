#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    unsigned int n; cin >> n;
    vector<pair<long double, long double>> list(n);
    for (auto &item : list) cin >> item.first;
    for (auto &item : list) item.second = 1 - item.first;
    sort(list.begin(), list.end());
    for (auto x : list)
    {
        // 1Q = YES * 0Q + NO * 1Q => Maximizing objective
        // NQ = YES * 1Q + NQ; 0Q = NO * 0Q
        /// 1Q = P * (0Q - 1Q) + 1Q; 0Q = (1 - P) * 0Q

    }
}