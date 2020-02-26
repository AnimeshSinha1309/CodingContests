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

struct Fragment {
    static int to_int(char ch) {
        if (isdigit(ch))
            return ch - '0';
        else if (islower(ch))
            return ch - 'a' + 10;
        else if (isupper(ch))
            return ch - 'A' + 36;
    }

    int a, b, c;
    friend istream &operator>>(istream &in, Fragment &f) {
        string s;
        cin >> s;
        f.a = to_int(s[0]);
        f.b = to_int(s[1]);
        f.c = to_int(s[2]);
        return in;
    }
    friend bool &operator==(Fragment &f_a, Fragment &f_b) {
        return (f_a.a == f_b.a) && (f_a.b == f_b.b) && (f_a.c == f_b.c);
    }
    friend void pick(vector<set<Fragment>> &list, Fragment &f, queue<ll> &q) {
    }
};

vector<Fragment> pieces;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    pieces.resize(n);
    for (int i = 0; i < n; i++)
        cin >> pieces[i];
}