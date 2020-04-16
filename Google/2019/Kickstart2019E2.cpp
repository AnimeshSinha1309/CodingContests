// Wrong Answer
// Tags: #BinarySearch #ExchangeArgument

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpl;

#define CODE first
#define EAT second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        // SEGMENT 1: Take the inputs and keep prefix and suffix sums
        // ==========================================================
        ll s, d;
        cin >> d >> s;
        vpl slots(s);
        for (int i = 0; i < s; i++)
            cin >> slots[i].CODE >> slots[i].EAT;
        // Sort by Exchange Argument
        // Decreasing Order of CODE / SPEED
        sort(slots.begin(), slots.end(),
             [](pll a, pll b) { return a.CODE * b.EAT > a.EAT * b.CODE; });
        vpl achieve(s);
        // Take the prefix sum of CODE points and suffix sum of SLEEP points
        achieve[0].CODE = 0, achieve[s - 1].EAT = 0;
        for (int i = 1; i < s; i++)
            achieve[i].CODE = achieve[i - 1].CODE + slots[i - 1].CODE;
        for (int i = s - 2; i >= 0; i--)
            achieve[i].EAT = achieve[i + 1].EAT + slots[i + 1].EAT;
        string ans(d, 'N');  // Assume that initially everything is NO
        // SEGMENT 2: Function to check the achievable value
        // =================================================
        enum Result {
            GO_LEFT, GO_RIGHT, ANSWER_YES, ANSWER_NO
        };
        auto check = [achieve, slots](pll req, ll val) {
            // Check if it's already solved
            if (achieve[val].CODE >= req.CODE && achieve[val].EAT >= req.EAT)
                return ANSWER_YES;
            // Go Left or Right if there is an abundance of that resource
            if (achieve[val].CODE > req.CODE)
                return GO_LEFT;
            if (achieve[val].EAT > req.EAT)
                return GO_RIGHT;
            // Take the remaining resource, and try to manage here
            // req.CODE / slots[val].CODE + req.SLEEP / slots[val].SLEEP <= 1
            req.CODE -= achieve[val].CODE;
            req.EAT -= achieve[val].EAT;
            if (req.CODE * slots[val].EAT + req.CODE * slots[val].EAT <=
                slots[val].CODE * slots[val].EAT)
                return ANSWER_YES;
            else
                return ANSWER_NO;
        };
        // SEGMENT 3: Binary Search over the domain for each query
        // =======================================================
        for (int q = 0; q < d; q++) {
            pll query;
            // Input each query
            cin >> query.CODE >> query.EAT;
            for (int top = s - 1, bot = 0, mid = (top + bot) / 2; bot <= top;
                 mid = (bot + top) / 2) {
                ll res = check(query, mid);
                // Answer YES or NO and break, or move left and right
                if (res == ANSWER_YES) {
                    ans[q] = 'Y';
                    break;
                } else if (res == ANSWER_NO) {
                    ans[q] = 'N';
                    break;
                } else if (res == GO_LEFT) {
                    top = mid - 1;
                } else if (res == GO_RIGHT) {
                    bot = mid + 1;
                }
            }
        }
        // SEGMENT 4: Print the result
        // ===========================
        cout << "Case #" << test << ": " << ans << endl;
    }
}