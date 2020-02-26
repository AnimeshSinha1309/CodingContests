#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    unsigned int n, m, k; cin >> n >> m >> k;
    vector<vector<short>> list(n+1, vector<short>(m, 0));
    for (int i = 1; i <= n; i++) for (int j = 0; j < m; j++) cin >> list[i][j];
    for (int i = 1; i <= n; i++) for (int j = 0; j < m; j++) list[i][j] += list[i-1][j];

}