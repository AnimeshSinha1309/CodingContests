#include <bits/stdc++.h>
using namespace std;

int n, m;                        // Size of registers and number of operations
vector<int> registers(1001, 0);  // The actual array of register values
vector<set<int>> tracker(3);     // Tracks the index registers which hold 0/1/2

// Adds to the Register value and updates trackers
void register_increment(int pos, int val) {
    if (registers[pos] <= 2)
        tracker[registers[pos]].erase(pos);
    registers[pos] += val;
    cout << pos << " " << registers[pos] << "  ";
    if (registers[pos] <= 2)
        tracker[registers[pos]].insert(pos);
}

int main() {
#ifdef ONLINE_JUDGE
    freopen("counter.in", "r", stdin);
    freopen("counter.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        tracker[0].insert(i);
    tracker[2].insert(n + 1);  // Dummy 2 at the end

    for (int i = 0, x; i < m; i++) {
        cin >> x;
        int next_2 = *tracker[2].upper_bound(x),
            prev_0 = *prev(tracker[0].upper_bound(next_2));
        if (x >= prev_0) {
            /* x can be 0/1/2, but there's no 0 from x to the next 2
             *  0 1 2 ... 2 1 ... 1 2
             * (^prev_0) (^x)      (^next_2)
             * We add normally to x while promoting the next 2
             * Assumption: x is not a 2 since the other operations will force
             * that between any two 2s there has to be a 0.
             */
            cout << 3 << "  ";
            register_increment(x, 1);
            register_increment(next_2, -2);
            register_increment(next_2 + 1, 1);
            cout << endl;
        } else if (registers[x] > 0) {
            /* There is no 0 from x to the next 2, x can be 1/2.
             * Assumption: Same as above, if there is no 0 in the middle, then
             * our current value can only be 1, since any two 2s will have a 0
             * to separate them.
             */
            cout << 2 << "  ";
            register_increment(x, -1);
            register_increment(x + 1, 1);
            cout << endl;
        } else {
            /* Here x is 0, and there is no 0 between x and 2, so just directly
             * increment this 0 to a 1.
             */
            cout << 1 << "  ";
            register_increment(x, 1);
            cout << endl;
        }
    }
    return 0;
}