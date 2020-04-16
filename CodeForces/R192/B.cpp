#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> mll;
typedef vector<pair<ll, ll>> vpl;
typedef long double ld;
typedef vector<long double> vld;
typedef vector<vector<long double>> mld;
typedef vector<bool> vbl;
typedef vector<vector<bool>> mbl;
#define minimize(a, b) (a = min(a, b))
#define maximize(a, b) (a = max(a, b))

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

ll n, m;
pll s, e;

void bfs(const mll &mat, mll &dist, pll from) {
    queue<pll> q;
    dist[from.first][from.second] = 0;
    q.emplace(from.first, from.second);
    while (!q.empty()) {
        pll p = q.front();
        q.pop();
        if (p.first + 1 < n && dist[p.first + 1][p.second] == INT64_MAX &&
            mat[p.first + 1][p.second] != -1) {
            dist[p.first + 1][p.second] = dist[p.first][p.second] + 1;
            q.push({p.first + 1, p.second});
        }
        if (p.second + 1 < m && dist[p.first][p.second + 1] == INT64_MAX &&
            mat[p.first][p.second + 1] != -1) {
            dist[p.first][p.second + 1] = dist[p.first][p.second] + 1;
            q.push({p.first, p.second + 1});
        }
        if (p.first - 1 >= 0 && dist[p.first - 1][p.second] == INT64_MAX &&
            mat[p.first - 1][p.second] != -1) {
            dist[p.first - 1][p.second] = dist[p.first][p.second] + 1;
            q.push({p.first - 1, p.second});
        }
        if (p.second - 1 >= 0 && dist[p.first][p.second - 1] == INT64_MAX &&
            mat[p.first][p.second - 1] != -1) {
            dist[p.first][p.second - 1] = dist[p.first][p.second] + 1;
            q.push({p.first, p.second - 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Initialize and Inputs
    cin >> n >> m;
    mll mat(n, vll(m, 0));
    mll s_dist(n, vll(m, INT64_MAX));
    mll e_dist(n, vll(m, INT64_MAX));
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            if (temp[j] == 'S')
                s = {i, j};
            else if (temp[j] == 'E')
                e = {i, j};
            else if (temp[j] == 'T')
                mat[i][j] = -1;
            else
                mat[i][j] = temp[j] - '0';
        }
    }
    // Get the shortest paths and distances to enemies
    bfs(mat, s_dist, s);
    bfs(mat, e_dist, e);
    ll dist = s_dist[e.first][e.second];
    // Check the answer by getting all enemies
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (e_dist[i][j] <= dist)
                ans += mat[i][j];
        }
    }
    cout << ans << endl;
}