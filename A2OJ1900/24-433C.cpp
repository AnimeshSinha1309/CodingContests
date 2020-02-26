#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    unsigned long n, m; cin >> n >> m;
    vector<long long> a(m); for (int i = 0; i < m; i++) cin >> a[i];
    vector<long long> dist(n+1, 0), move(n+1, 0), save(n+1, 0); vector<vector<long long>> neighbors(n+1);
    for (int i = 0; i < m; i++) {
        if (i < m-1 && a[i] != a[i+1]) { dist[a[i+1]] += abs(a[i+1] - a[i]); neighbors[a[i+1]].push_back(a[i]); }
        if (i >   0 && a[i] != a[i-1]) { dist[a[i-1]] += abs(a[i-1] - a[i]); neighbors[a[i-1]].push_back(a[i]); }
    }
    for (int i = 0; i <= n; i++) {
        if (neighbors[i].empty()) continue;
        sort(neighbors[i].begin(), neighbors[i].end());
        move[i] = neighbors[i][neighbors[i].size()/2];
        for (long long neighbor : neighbors[i]) save[i] += abs(neighbor - i) - abs(neighbor - move[i]);
    }
    long replaced = max_element(save.begin(), save.end()) - save.begin();
    for (int i = 0; i < m; i++) if (a[i] == replaced) a[i] = move[replaced];
    long long pages = 0; for (int i = 1; i < m; i++) pages += abs(a[i] - a[i-1]);
    cout << pages << endl;
}