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
const long long MOD = (ll)1e9;

template<typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
    ll n = vec.size();
    for (int i = 0; i < n; i++)
        in >> vec[i];
    return in;
}

template<typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    out << endl;
    return out;
}

struct Result {
    ll x, y;
    int till;

    explicit Result(ll _ew = 0, ll _ns = 0, ll _till = 0) : x(_ew), y(_ns), till(_till) {
    }
    void put_char(char ch) {
        if (ch == 'E') x = (x + 1) % MOD;
        if (ch == 'W') x = (x + MOD - 1) % MOD;
        if (ch == 'S') y = (y + 1) % MOD;
        if (ch == 'N') y = (y + MOD - 1) % MOD;
        till++;
    }
    friend Result operator +(Result a, Result b) {
        return Result((a.x + b.x) % MOD, (a.y + b.y) % MOD, max(a.till, b.till) + 1);

    }
    friend Result operator *(Result a, char b) {
        return Result((a.x * (b - '0')) % MOD, (a.y * (b - '0')) % MOD, a.till);
    }

    void print() { cout << ">>> " << x << " " << y << endl; }
};

Result parse(const string &s, int pos = 0) {
    Result ans(0, 0, pos);
    while (ans.till < s.size()) {
        char ch = s[ans.till];
        if (ch == ')') return ans;
        else if ('2' <= ch && ch <= '9') ans = ans + (parse(s, ans.till + 2) * ch);
        else ans.put_char(ch);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        string st; cin >> st;
        Result ans = parse(st);
        cout << "Case #" << test << ": " << ans.x + 1 << " " << ans.y + 1 << endl;
    }
}