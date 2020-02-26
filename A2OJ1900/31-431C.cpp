#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int main() {
    int n, k, d; cin >> n >> k >> d;
    vector<long long> wK((unsigned)n+1, 0); wK[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k && i - j >= 0; j++) {
            wK[i] = (wK[i] + wK[i - j]) % MOD;
        }
    }
    vector<long long> wD((unsigned)n+1, 0); wD[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < d && i - j >= 0; j++) {
            wD[i] = (wD[i] + wD[i - j]) % MOD;
        }
    }
    cout << (wK[n] - wD[n] + MOD) % MOD << endl;
}