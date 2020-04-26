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

vector<string> digits = {"1110111", "0010010", "1011101", "1011011", "0111010",
                         "1101011", "1101111", "1010010", "1111111", "1111011"};

int is_possible(const string &given, const string &target) {
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        if (given[i] == '0' && target[i] == '1')
            ans++;
        else if (given[i] == '1' && target[i] == '0')
            return -1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Input and Initialize
    ll n, k;
    cin >> n >> k;
    mbl possible(n + 1, vbl(k + 1, false));
    mll val(n, vll(10, -1));
    // Store the input well
    for (int i = 0; i < n; i++) {
        string st;
        cin >> st;
        for (int d = 0; d < 10; d++) {
            int on = is_possible(st, digits[d]);
            val[i][d] = on;
        }
    }
    // Make the possible matrix
    possible[n][0] = true;
    for (int i = n - 1; i >= 0; i--) {
        set<int> shifts;
        for (int d = 0; d < 10; d++) {
            if (val[i][d] != -1)
                shifts.insert(val[i][d]);
        }
        for (auto shift : shifts) {
            for (int j = 0; j + shift <= k; j++) {
                possible[i][j + shift] =
                    possible[i + 1][j] || possible[i][j + shift];
            }
        }
    }
    // Compute the answer
    if (!possible[0][k]) {
        cout << -1 << endl;
        return 0;
    }
    string s = "";
    for (int i = 0; i < n; i++) {
        for (int d = 9; d >= 0; d--) {
            if (val[i][d] == -1)
                continue;
            if (k >= val[i][d] && possible[i + 1][k - val[i][d]]) {
                s.push_back('0' + d);
                k -= val[i][d];
                break;
            }
        }
    }
    cout << s << endl;
}