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
    // Take the input
    ll n, k;
    cin >> n >> k;
    vll digits_n;
    for (ll copy = n; copy > 0; copy /= 10)
        digits_n.push_back(copy % 10);
    reverse(digits_n.begin(), digits_n.end());
    // Get the number of people in each weight category
    vll wt(180, 0);
    wt[0] = 1;
    ll wt_top = 0;
    for (auto digit : digits_n) {
        vll wt_copy(180);
        wt_top += digit;
        for (int this_digit = 0; this_digit < digit; this_digit++) {
            wt_copy[wt_top + this_digit]++;
        }
        for (int this_digit = 0; this_digit < 10; this_digit++) {
            for (int wt_prev = 0; wt_prev < 180; wt_prev++) {
                if (wt_prev > 0)
                    wt_copy[wt_prev + this_digit] += wt[wt_prev];
            }
        }
        wt = wt_copy;
    }
    // Get our weight category, and people before us

    // Do the Digit DP over people before us
}