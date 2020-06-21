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

enum Direction { NORTH, SOUTH, EAST, WEST };
pll drive(pll state, Direction dir) {
    if (dir == NORTH)
        return {state.first, state.second - 1};
    else if (dir == SOUTH)
        return {state.first, state.second + 1};
    else if (dir == EAST)
        return {state.first - 1, state.second};
    else if (dir == WEST)
        return {state.first + 1, state.second};
    assert(false);
    return {-1, -1};
}
Direction turn(Direction dir, char move) {
    if (move == 'F')
        return dir;
    else if (move == 'L') {
        if (dir == NORTH)
            return EAST;
        if (dir == EAST)
            return SOUTH;
        if (dir == SOUTH)
            return WEST;
        if (dir == WEST)
            return NORTH;
    } else if (move == 'R') {
        if (dir == NORTH)
            return WEST;
        if (dir == EAST)
            return NORTH;
        if (dir == SOUTH)
            return EAST;
        if (dir == WEST)
            return SOUTH;
    }
    assert(false);
    return NORTH;
}
ll peek(mll &dist, pll pos, Direction dir) {
    pll next_pos = drive(pos, dir);
    return dist[next_pos.first][next_pos.second];
}
ll peek(mll &dist, pll pos) {
    return dist[pos.first][pos.second];
}

int main(void) {
    freopen("straight.in", "r", stdin);
    freopen("straight.out", "w", stdout);
    int n = 0, m = 0;
    cin >> n >> m;
    vector<string> grid(2 * n - 1);
    mll distance = mll(2 * n - 1, vll(2 * m - 1, INT32_MAX));
    string _dummy;
    getline(cin, _dummy);
    for (int i = 0; i < 2 * n - 1; i++)
        getline(cin, grid[i]);
    distance[1][2 * m - 1] = 0;
    // Do the DP Shortest Path algorithm
    queue<pll> q;
    q.push(pll(1, 2 * m - 1));
    vector<Direction> directions = {NORTH, SOUTH, EAST, WEST};
    while (!q.empty()) {
        pll cur = q.front();
        q.pop();
        for (auto dir : directions) {
            pll next = drive(cur, dir);
            if (grid[next.first][next.second] == ' ')
                continue;
            if (peek(distance, cur) + 1 < peek(distance, next)) {
                distance[cur.first][cur.second] = peek(distance, next) + 1;
                q.push(next);
            }
        }
    }
    // Now get to driving
    pll pos = {2 * n - 1, 1};
    Direction dir = (peek(distance, pos, NORTH) <= peek(distance, pos, EAST))
                        ? NORTH
                        : EAST;
    drive(pos, dir);
    cout << (dir == NORTH ? 'N' : 'E') << endl;

    while (pos.first != 1 || pos.second != 2 * m - 1) {
        if (grid[pos.first][pos.second] == '+')
            continue;
        if (peek(distance, pos, dir) == peek(distance, pos) - 1) {
            cout << 'F';
        } else if (peek(distance, pos, turn(dir, 'R')) ==
                   peek(distance, pos) - 1) {
            cout << 'R';
            dir = turn(dir, 'R');
        } else if (peek(distance, pos, turn(dir, 'L')) ==
                   peek(distance, pos) - 1) {
            cout << 'L';
            dir = turn(dir, 'L');
        }
        pos = drive(pos, dir);
    }
    return 0;
}
