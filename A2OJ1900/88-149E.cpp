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

class KMPstring {
    string pattern;
    vll lps;

   public:
    explicit KMPstring(const string &pattern) {
        this->pattern = pattern;
        ll m = pattern.size();
        lps = vll(m + 1, 0);
        ll i = 0, j = -1;
        lps[0] = -1;
        while (i < m) {
            while (j >= 0 && pattern[i] != pattern[j])
                j = lps[j];
            i++, j++;
            lps[i] = j;
        }
    }
    vll match(const string &text) {
        ll n = text.size(), m = pattern.size();
        vll matches, m_length(n);
        ll i = 0, j = 0;
        while (i < n) {
            while (j >= 0 && text[i] != pattern[j])
                j = lps[j];
            i++, j++;
            m_length[i - 1] = j;
            if (j == m) {
                matches.push_back(i - m);
                j = lps[j];
            }
        }
        return m_length;  // move(matches);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Take the inputs and call the KMP functions
    string s_f;
    cin >> s_f;
    string s_r(s_f);
    reverse(s_r.begin(), s_r.end());
    ll n, sz = s_f.size();
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string t_f;
        cin >> t_f;
        string t_r(t_f);
        reverse(t_r.begin(), t_r.end());
        KMPstring k_f(t_f);
        KMPstring k_r(t_r);
        vll deg_f = k_f.match(s_f);
        vll deg_r = k_r.match(s_r);
        reverse(deg_r.begin(), deg_r.end());
        ll prefix_match = 0, p_sz = t_f.size();
        for (int i = 0; i < sz; i++) {
            if (deg_r[i] + prefix_match >= p_sz && deg_r[i] > 0 &&
                prefix_match > 0 && p_sz > 1) {
                ans++;
                break;
            } else {
                maximize(prefix_match, deg_f[i]);
            }
        }
    }
    cout << ans << endl;
}
