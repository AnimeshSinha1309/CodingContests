#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned int n, k;
vector<long long> list;

bool check(long value) {
    for (auto el : list) {
        if (el % value > k) return false;
    } return true;
}

int main() {
    cin >> n >> k; list = vector<long long>(n); for (auto &item : list) cin >> item;
    unsigned int result = 0;
    for (long top = 1000000, bot = 1, mid = (top + bot)/2; bot <= top; mid = (bot + top) / 2) {
        if (check(mid) && !check(mid+1)) { result = (unsigned)mid; break; }
        (!check(mid)) ? (top = mid - 1) : (bot = mid + 1);
    }
    cout << result << endl;
}