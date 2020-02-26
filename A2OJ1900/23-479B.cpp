#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    unsigned int n, k, temp, m = 0; cin >> n >> k;
    set<pair<int,int>> list; vector<pair<int,int>> operations;
    for (int i = 0; i < n; i++) { cin >> temp; list.emplace(temp, i + 1); }
    for (m = 0; m < k && list.rbegin()->first - list.begin()->first > 1; m++) {
        pair<int,int> elMax = *list.rbegin(), elMin = *list.begin();
        list.erase(list.begin()); list.erase(--list.end());
        elMax.first--; elMin.first++;
        list.insert(elMax); list.insert(elMin);
        operations.emplace_back(elMax.second, elMin.second);
    }
    cout << list.rbegin()->first - list.begin()->first << " " << m << endl;
    for (const auto &op : operations) cout << op.first << " " << op.second << endl;
}