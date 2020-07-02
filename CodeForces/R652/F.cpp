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

bool play_to_win(ll e, ll s);
bool play_to_lose(ll e, ll s);

bool play_to_win(ll e, ll s) {
    if (s == e)
        return true;
    if (2 * s > e) {
        // Play slowly towards the end
        return s % 2 != e % 2;
    }
    if (e % 2 == 0) {
        // If goal is even, play to e/2 loses
        return play_to_lose(e / 2, s);
    } else {
        // If goal is odd, player with odd holds and wins
        return s % 2 == e % 2;
    }
}

bool play_to_lose(ll e, ll s) {
    if (2 * s > e) {
        // Lose immediately
        return true;
    }
    // Force opponent to write the first jumpable number
    return !play_to_win(e / 2, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vpl q(n);
    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;
    pair<bool, bool> state = {play_to_win(q[n - 1].second, q[n - 1].first),
                              play_to_lose(q[n - 1].second, q[n - 1].first)};
    cout << '#' << state.first << state.second << endl;
    for (int i = n - 2; i >= 0; i--) {
        pair<bool, bool> x = {play_to_win(q[i].second, q[i].first),
                              play_to_lose(q[i].second, q[i].first)};
        pair<bool, bool> cur;
        cur.first = (x.first && !state.first) || (x.second && state.first);
        cur.second = (x.first && !state.second) || (x.second && state.second);
        state = cur;
        cout << '#' << x.first << x.second << endl;
    }
    cout << (state.first ? '1' : '0') << ' ' << (state.second ? '1' : '0')
         << endl;
}