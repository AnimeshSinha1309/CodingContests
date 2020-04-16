#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<bool> vbl;
typedef vector<vector<ll>> mll;

int main() {
    freopen("jingles.in", "r", stdin);
    freopen("jingles.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        // Take the input and initialize
        string str;
        cin >> str;
        ll n = str.size();
        map<ll, ll> length_of_set;
        vll index(26, n);
        mll next(n, vll(26, -1));
        // Compute the next pointers
        for (ll i = n - 1; i >= 0; i--) {
            for (ll j = 0; j < 26; j++) {
                next[i][j] = index[j];
            }
            index[str[i] - 'a'] = i;
        }
        // Loop over all starting poitions
        for (ll i = 0; i < n; i++) {
            vbl visited_set(26, false);
            visited_set[str[i] - 'a'] = true;
            ll mask = 1 << (str[i] - 'a'), pointer = i;
            while (pointer < n) {
                // Compute next jump spot
                ll next_pointer = n;
                for (ll j = 0; j < 26; j++) {
                    if (visited_set[j] == 0 && next[pointer][j] != n) {
                        next_pointer = min(next_pointer, next[pointer][j]);
                    }
                }
                // Update the length of the mask
                length_of_set[mask] =
                    max(length_of_set[mask], next_pointer - i);
                pointer = next_pointer;
                // Update the current visited state
                if (next_pointer != n) {
                    ll ch = str[next_pointer] - 'a';
                    visited_set[ch] = true;
                    mask += (1ll << ch);
                }
            }
        }
        // Compute the count and the sum
        ll count = 0, sum = 0;
        for (auto it : length_of_set) {
            if (it.first != 0) {
                count++;
                sum += it.second * __builtin_popcount(it.first);
            }
        }
        cout << count << " " << sum << endl;
    }
    return 0;
}