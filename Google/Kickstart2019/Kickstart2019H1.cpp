#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpl;
#define minimize(a, b) (a = min(a, b);)
#define maximize(a, b) (a = max(a, b);)

int main() {
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        cout << "Case #" << test << ": ";
        ll n;
        cin >> n;
        vll a(n, 0);
        vll c(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        priority_queue<ll, vll, greater<>> q;
        for (int i = 0; i < n; i++) {
            q.push(a[i]);
            // There are h numbers >= h
            while (q.size() > q.top())
                q.pop();
            cout << q.size() << " ";
        }
        cout << endl;
    }
}