#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = -n/2; i <= n/2; i++) {
        for (int j = -n/2; j <= n/2; j++)
            cout << ((abs(i) + abs(j) <= n/2) ? 'D' : '*');
        cout << endl;
    }
}