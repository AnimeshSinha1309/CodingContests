#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef long double ld;
typedef vector<long double> vld;
typedef vector<vector<long double>> mld;
typedef vector<bool> vbl;
typedef vector<vector<bool>> mbl;
#define minimize(a, b) (a = min(a, b))
#define maximize(a, b) (a = max(a, b))
const long long MOD = 1e9 + 7;

template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
    ll n = vec.size();
    for (int i = 0; i < n; i++)
        in >> vec[i];
    return in;
}
template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    out << endl;
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vll supply(n);
    vbl served(m, false);
    cin >> supply;
    vpl favorites(m);
    for (int i = 0; i < m; i++)
        cin >> favorites[i].first >> favorites[i].second;
    vll demand(n);
    for (int i = 0; i < m; i++)
        demand[favorites[i].first]++, demand[favorites[i].second]++;
    queue<ll> q;
    for (int i = 0; i < n; i++)
        if (demand[i] >= supply[i])
            q.push(i);
    mll demanders_of_food(n);
    for (int i = 0; i < m; i++)
        demanders_of_food[favorites[i].first].push_back(i),
            demanders_of_food[favorites[i].second].push_back(i);

    while (!q.empty()) {
        served[q.front()] = true;
        for (auto demander : demanders_of_food[q.front()]) {
            served[demander] = true;
            demand[favorites[demander].first]--;
            if (demand[favorites[demander].first] ==
                supply[favorites[demander].first])
                q.push(favorites[demander].first);
            demand[favorites[demander].second]--;
            if (demand[favorites[demander].second] ==
                supply[favorites[demander].second])
                q.push(favorites[demander].second);
        }
        q.pop();
    }
}