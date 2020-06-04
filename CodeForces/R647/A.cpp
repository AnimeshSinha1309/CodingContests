#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpl;
typedef vector<bool> vbl;

int main() {
    // Take input
    ll n, m;
    cin >> n >> m;
    vpl edges(m);
    for (auto &edge : edges) {
        cin >> edge.first >> edge.second;
        edge.first--;
        edge.second--;
    }
    vpl topics(n);
    for (int i = 0; i < n; i++) {
        cin >> topics[i].first;
        topics[i].second = i + 1;
    }
    // Check self loop of topics
    for (auto edge : edges) {
        if (topics[edge.first].first == topics[edge.second].first) {
            cout << -1 << endl;
            exit(0);
        }
    }
    // Check previous connection
    vbl prev(n, false);
    for (int i = 0; i < n; i++) {
        if (topics[i].first == 1)
            prev[i] = true;
    }
    for (auto edge : edges) {
        if (topics[edge.first].first + 1 == topics[edge.second].first)
            prev[edge.second] = true;
        if (topics[edge.second].first + 1 == topics[edge.first].first)
            prev[edge.first] = true;
    }
    for (auto el : prev) {
        if (el == false) {
            cout << -1 << endl;
            exit(0);
        }
    }
    // Output natural order
    sort(topics.begin(), topics.end());
    for (int i = 0; i < n; i++)
        cout << topics[i].second << " ";
    cout << endl;
}