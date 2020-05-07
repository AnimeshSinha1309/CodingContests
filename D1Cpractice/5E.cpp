#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

long long solve(vector<int> h) {
    int n = h.size();
    deque<int> s;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && h[s.front()] < h[i])
            s.pop_front();
        s.push_front(i);
    }
    for (int i = 0; i < n; i++) {
        ans += s.size();
        cout << "@@@" << ans << endl;
        while (!s.empty() && h[s.front() % n] < h[i])
            s.pop_front();
        s.push_front(n + i);
        while (s.back() <= i + 1)
            s.pop_back();
    }
    cout << ">>>" << ans << endl;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    vector<int> g(h);
    reverse(g.begin(), g.end());
    cout << (solve(h) + solve(g)) / 4 + 1 << endl;
}
