#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool result = false;

void conquer(const int i, const int j, const int id, const vector<vector<char>> &grid, vector<vector<int>> &cluster,
        const unsigned int n, const unsigned int m, const int pi, const int pj) {
    if (cluster[i][j] == id) { result = true; return; }
    if (cluster[i][j] != 0) return; else cluster[i][j] = id;
    if (i > 0   && grid[i-1][j] == grid[i][j] && i-1 != pi) conquer(i-1, j, id, grid, cluster, n, m, i, j);
    if (i < n-1 && grid[i+1][j] == grid[i][j] && i+1 != pi) conquer(i+1, j, id, grid, cluster, n, m, i, j);
    if (j > 0   && grid[i][j-1] == grid[i][j] && j-1 != pj) conquer(i, j-1, id, grid, cluster, n, m, i, j);
    if (i < m-1 && grid[i][j+1] == grid[i][j] && j+1 != pj) conquer(i, j+1, id, grid, cluster, n, m, i, j);
}

int main() {
    unsigned int n, m, id = 1;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '1'));
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for (int j = 0; j < m; j++) grid[i][j] = temp[j];
    }
    vector<vector<int>> component(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (component[i][j] == 0) conquer(i, j, id++, grid, component, n, m, INT32_MAX, INT32_MAX);
        }
    }
    cout << (result ? "Yes" : "No") << endl;
}