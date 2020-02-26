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

vector<vll> points;
#define sq(x) ((x) * (x))
#define permute(i) next_permutation(points[i].begin(), points[i].end())

bool check() {
    vll dist;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            dist.push_back(sq(points[i][0] - points[j][0]) +
                           sq(points[i][1] - points[j][1]) +
                           sq(points[i][2] - points[j][2]));
        }
    }
    sort(dist.begin(), dist.end());
    vpl edges;
    for (int i = 1, c = 1; i <= 28; i++, c++) {
        if (i == 28 || dist[i] != dist[i - 1])
            edges.emplace_back(dist[i - 1], c), c = 0;
    }
    bool res = edges.size() == 3 && edges[0].first * 2 == edges[1].first &&
               edges[0].first * 3 == edges[2].first && edges[0].second == 12 &&
               edges[1].second == 12 && edges[2].second == 4 &&
               edges[0].first != 0;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    points = vector<vll>(8, vll(3));
    bool found = false;
    for (int i = 0; i < 8; i++) {
        cin >> points[i][0] >> points[i][1] >> points[i][2];
        sort(points[i].begin(), points[i].end());
    }
    for (bool valid = true; valid; valid = permute(1))
        for (bool valid = true; valid; valid = permute(2))
            for (bool valid = true; valid; valid = permute(3))
                for (bool valid = true; valid; valid = permute(4))
                    for (bool valid = true; valid; valid = permute(5))
                        for (bool valid = true; valid; valid = permute(6))
                            for (bool valid = true; valid; valid = permute(7)) {
                                if (check()) {
                                    cout << "YES" << endl;
                                    for (int i = 0; i < 8; i++)
                                        cout << points[i][0] << " "
                                             << points[i][1] << " "
                                             << points[i][2] << endl;
                                    return 0;
                                }
                            }
    cout << "NO" << endl;
}