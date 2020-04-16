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
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll n = s.size();
        // Cache all substring palindromes
        mbl is_palindrome(n, vbl(n + 1, false));
        for (int i = 0; i < n; i++)
            is_palindrome[i][1] = true, is_palindrome[i][0] = true;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                is_palindrome[i][len] =
                    (s[i] == s[i + len - 1]) && is_palindrome[i + 1][len - 2];
            }
        }
        // Find the answers by matching
        pll ans = {0, 0};
        for (int prefix_len = 0; prefix_len <= n; prefix_len++) {
            for (int suffix_len = 0; suffix_len <= n; suffix_len++) {
                // t exceeds the length of s
                if (prefix_len + suffix_len > n)
                    continue;
                // The extra parts don't match
                if (suffix_len > 0 && suffix_len <= prefix_len &&
                    s[suffix_len - 1] != s[n - suffix_len])
                    break;
                // Check if the rest is palindrome and maximize
                if (prefix_len > suffix_len)
                    if (is_palindrome[suffix_len][prefix_len - suffix_len])
                        if (prefix_len + suffix_len >= ans.second + ans.first)
                            ans = {prefix_len, suffix_len};
                if (prefix_len < suffix_len)
                    if (is_palindrome[n - suffix_len][suffix_len - prefix_len])
                        if (prefix_len + suffix_len >= ans.second + ans.first)
                            ans = {prefix_len, suffix_len};
            }
        }
        // Print out the answers
        for (int i = 0; i < ans.first; i++)
            cout << s[i];
        for (int i = n - ans.second; i < n; i++)
            cout << s[i];
        cout << endl;
    }
}