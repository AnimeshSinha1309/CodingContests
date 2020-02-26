#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    unsigned int n, k, d; cin >> n >> k >> d;
    vector<vector<int>> bus(n, vector<int>(d, 0));
    for (int i = 0; i < n; i++) {
        bus[i][0] = i;
        for (int j = 0; j < d-1; j++) {
            bus[i][j+1] += bus[i][j] / k;
            bus[i][j] = bus[i][j] % k;
        } if (bus[i][d-1] >= k) { cout << -1; return 0; }
    }
    for (int day = 0; day < d; day++) {
        for (int child = 0; child < n; child++) {
            cout << bus[child][day] + 1 << " ";
        } cout << endl;
    }
}