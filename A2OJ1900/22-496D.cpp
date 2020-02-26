#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<short> list((unsigned)n); for (auto &item : list) cin >> item;
    vector<pair<int,int>> score((unsigned)n, {0, 0});
    for (int i = 0, s1 = 0, s2 = 0; i < n; i++) { if (list[i] == 1) s1++; else s2++; score[i] = {s1, s2}; }
    vector<int> score1(n+n+2, INT32_MAX), score2(n+n+2, INT32_MAX);
    for (int i = 0, ptr1 = 0, ptr2 = 0; i < n; i++) {
        if (list[i] == 1) score1[++ptr1] = i;
        if (list[i] == 2) score2[++ptr2] = i;
    }
    vector<pair<int,int>> result;
    for (int t = 1; t <= n; t++) {
        int points1 = 0, points2 = 0, sets1 = 0, sets2 = 0, pos = -1;
        while (pos < n-1) {
            if (score1[points1 + t] < n && score1[points1 + t] < score2[points2 + t]) {
                pos = score1[points1 + t];
                points1 = score[pos].first;
                points2 = score[pos].second;
                sets1++;
            } else if (score2[points2 + t] < n) {
                pos = score2[points2 + t];
                points1 = score[pos].first;
                points2 = score[pos].second;
                sets2++;
            } else break;
        } if (pos == n-1) result.emplace_back(max(sets1, sets2), t);
    }
    cout << result.size() << endl;
    for (auto item : result) cout << item.first << " " << item.second << endl;
}