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
ostream &operator<<(ostream &out, bool &val) {
    if (val)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return out;
}

struct Paper {
    short a, b, c;
    Paper(string st) {
        a = numeric(st[0]);
        b = numeric(st[1]);
        c = numeric(st[2]);
    }
    short numeric(char ch) {
        if (isupper(ch))
            return ch - 'A';
        else if (islower(ch))
            return ch - 'a' + 26;
        else
            return ch - '0' + 52;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<Paper> a(n);
    for (int i = 0; i < n; i++) {
        string st;
        cin >> st;
        a[i] = Paper(st);
    }
    vll count(62, 0);
    for (int i = 0; i < n; i++) {
        count[a[i].a]++;
        count[a[i].b]++;
        count[a[i].c]++;
    }
    queue<ll> pos;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            pos.push(i);
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            pos.push(i);
            break;
        }
    }
}