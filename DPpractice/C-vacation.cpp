#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long sum = 0;
    vector<long long> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    vector<long long> dp_a(n + 1, 0), dp_b(n + 1, 0), dp_c(n + 1, 0);
    for (int i = 0; i < n; i++) {
        dp_a[i + 1] = max(dp_a[i], a[i] + max(dp_b[i], dp_c[i]));
        dp_b[i + 1] = max(dp_b[i], b[i] + max(dp_c[i], dp_a[i]));
        dp_c[i + 1] = max(dp_c[i], c[i] + max(dp_a[i], dp_b[i]));
    }
    cout << max(dp_a[n], max(dp_b[n], dp_c[n])) << endl;
}