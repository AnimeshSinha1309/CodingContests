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
    ll n, q; cin >> n >> q;
    vll power(n); cin >> power;
    // Square-root decomposition
    ll block_size = (ll) sqrt(n);
    ll block_count = (ll) (n + block_size - 1) / block_size;
    power.resize(block_count * block_size, 0);
    // Pre-computing the next blocks
    vll times(power.size(), 0), final(power.size(), -1);
    for (int i = n - 1; i >= 0; i--) {
        if ((i + power[i]) / block_size > i / block_size || i + power[i] >= n)
            times[i] = 0, final[i] = i;
        else
            times[i] = times[i + power[i]] + 1, final[i] = final[i + power[i]];
    }
    // Answering the queries
    for (int qi = 0; qi < q; qi++) {
        int t; cin >> t;
        if (t == 0) {
            // Change the last square reached for the entire block when updating
            int a, b; cin >> a >> b; a--;
            power[a] = b;
            for (int iter = block_size - 1, offset = a / block_size; iter >= 0; iter--) {
                int i = iter + offset;
                if ((i + power[i]) / block_size > i / block_size || i + power[i] >= n)
                    times[i] = 0, final[i] = i;
                else
                    times[i] = times[i + power[i]] + 1, final[i] = final[i + power[i]];
            }
        } else {
            // Jump and next when traversing for all the blocks
            int a; cin >> a; a--;
            int count = 0;
            while (a + power[a] < n) {
                if (a == final[a])
                    a += power[a], count++;
                else
                    count += times[a], a = final[a];
            }
            cout << a + 1 << " " << count + 1 << endl;
        }
    }
}