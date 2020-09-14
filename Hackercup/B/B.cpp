#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
const ll MOD = 1e9 + 7;

bool check(vll &q, vll &p, ll time) {
    ll j = 0, start = p[0];
    for (int i = 0; i < p.size(); i++) {
        while ((p[i] - start) + min(abs(q[j] - start), abs(q[j] - p[i])) >
               time) {
            j++;
            start = p[i];
            if (j == q.size())
                return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        // Take the inputs
        ll n, m, k, s;
        cin >> n >> m >> k >> s;
        vll p(n), q(m);
        ll a_p, b_p, c_p, d_p;
        ll a_q, b_q, c_q, d_q;
        for (int i = 0; i < k; i++)
            cin >> p[i];
        cin >> a_p >> b_p >> c_p >> d_p;
        for (int i = 0; i < k; i++)
            cin >> q[i];
        cin >> a_q >> b_q >> c_q >> d_q;
        for (int i = k; i < n; i++)
            p[i] = (a_p * p[i - 2] + b_p * p[i - 1] + c_p) % d_p + 1;
        for (int i = k; i < m; i++)
            q[i] = (a_q * q[i - 2] + b_q * q[i - 1] + c_q) % d_q + 1;
        // Binary Search over answer
        sort(p.begin(), p.end());
        sort(q.begin(), q.end());
        ll result = 0;
        for (ll top = 2 * max(d_p, d_q), bot = 0, mid = bot + (top - bot) / 2;
             bot <= top; mid = bot + (top - bot) / 2) {
            if (check(p, q, mid) && !check(p, q, mid - 1)) {
                result = mid;
                break;
            }
            (check(p, q, mid)) ? (top = mid - 1) : (bot = mid + 1);
        }
        // Print the output
        cout << "Case #" << test << ": " << result << '\n';
    }
}