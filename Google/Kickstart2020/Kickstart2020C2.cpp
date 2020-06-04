#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<bool> vbl;
typedef vector<vector<bool>> mbl;

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        ll r, c;
        cin >> r >> c;
        vector<string> wall(r);
        for (int i = 0; i < r; i++)
            cin >> wall[i];
        mbl depends(26, vbl(26, false));
        vbl appears(26, false);

        ll count = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!appears[wall[i][j] - 'A'])
                    count++;
                appears[wall[i][j] - 'A'] = true;
            }
        }
        for (int i = 0; i < r - 1; i++) {
            for (int j = 0; j < c; j++) {
                int l1 = wall[i][j] - 'A', l2 = wall[i + 1][j] - 'A';
                if (l1 != l2 && !depends[l1][l2]) {
                    depends[l1][l2] = true;
                }
            }
        }
        string ans;
        for (int i = 0; i < 26; i++) {
            int l = -1;
            bool works;
            do {
                l++;
                works = false;
                if (!appears[l])
                    continue;
                works = true;
                for (int j = 0; j < 26; j++)
                    if (appears[j] && depends[l][j])
                        works = false;
            } while (l < 26 && !works);

            if (l >= 26)
                break;
            ans.push_back(l + 'A');
            appears[l] = false;
        }
        cout << "Case #" << test << ": " << ((ans.size() == count) ? ans : "-1")
             << endl;
    }
}