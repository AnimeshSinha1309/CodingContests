#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

unsigned long n, m, k;
vector<vector<long long>> droids;
vector<deque<long long>> fire;

bool check(long kill) {
    for (int j = 0; j < m; j++) while (!fire[j].empty()) fire[j].pop_back();
    if (kill == 0) return true;
    for (int pos = 0; pos < n; pos++) {
        for (int j = 0; pos < n && j < m; j++)
            while (!fire[j].empty() && fire[j].front() <= pos - kill) fire[j].pop_front();
        for (int j = 0; j < m; j++) {
            while (!fire[j].empty() && droids[fire[j].back()][j] <= droids[pos][j]) fire[j].pop_back();
            fire[j].push_back(pos);
        } long long shots = 0; for (int j = 0; j < m; j++) shots += droids[fire[j].front()][j];
        if (pos >= kill - 1 && shots <= k) return true;
    } return false;
}

int main() {
    cin >> n >> m >> k; droids = vector<vector<long long>>(n, vector<long long>(m, 0));
    fire = vector<deque<long long>>(m);
    for (auto &droid : droids) for (auto &detail : droid) cin >> detail;
    unsigned int result = 0;
    for (long top = n, bot = 0, mid = (top + bot)/2; bot <= top; mid = (bot + top) / 2) {
        if (!check(mid+1) && check(mid)) { result = (unsigned)mid; break; }
        (!check(mid)) ? (top = mid - 1) : (bot = mid + 1);
    }
    for (int j = 0; j < m; j++) cout << (!fire[j].empty() ? droids[fire[j].front()][j] : 0) << " "; cout << endl;
}