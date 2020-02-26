#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);
    ll n;
    cin >> n;
    vll p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    priority_queue<ll, vector<ll>, greater<>> q;
    for (auto el : p)
        q.push(el);
    ll ans = 0;
    while (q.size() >= 2) {
        ll top1 = q.top();
        q.pop();
        ll top2 = q.top();
        q.pop();
        ans += top1 + top2;
        q.push(top1 + top2);
    }
    cout << ans << endl;
}