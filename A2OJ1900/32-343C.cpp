#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(const vector<long long> &h, const vector<long long> &p, long long time) {
    pair<long long, long long> r = {0, -1}; long long ptr = 0;
    while (r.second < (long long)p.size() - 1) {
        if (abs(p[r.second + 1]-p[r.first]) + min(abs(p[r.second + 1]-h[ptr]), abs(p[r.first]-h[ptr])) <= time)
            r.second++;
        else { r = { r.second + 1, r.second }; ptr++; if (ptr >= h.size()) return false; }
    } return true;
}

int main() {
    unsigned long long n, m; cin >> n >> m;
    vector<long long> h(n); for (auto &item : h) cin >> item;
    vector<long long> p(m); for (auto &item : p) cin >> item;
    long long result = INT64_MAX;
    for (long long top = 20000000000, bot = 0, mid = (top + bot)/2; bot <= top; mid = (bot + top) / 2) {
        if (check(h, p, mid) && !check(h, p, mid-1)) { result = mid; break; }
        (check(h, p, mid)) ? (top = mid - 1) : (bot = mid + 1);
    } cout << result << endl;
}
