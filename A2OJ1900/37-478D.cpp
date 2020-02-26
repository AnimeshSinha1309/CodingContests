#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int main() {
    long long r, g, answer = 0; cin >> r >> g;
    long long h = 0; while ((h + 1) * (h + 2) / 2 <= r + g) h++;
    long long rMax = r, rMin = max(h * (h + 1) / 2 - g, 0ll);
    if (rMax < rMin) swap(rMax, rMin);
    vector<long long> ways((unsigned)rMax + 1, 0); ways[0] = 1;
    for (int size = 1; size <= h; size++) {
        for (long long i = rMax - size; i >= 0; i--) {
            ways[i+size] = (ways[i+size] + ways[i]) % MOD;
        }
    }
    for (long long i = rMin; i <= rMax; i++) {
        answer = (answer + ways[i]) % MOD;
    } cout << answer << endl;
}