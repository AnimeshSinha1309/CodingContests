#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;

VI regions;
VVI allpaths;
vector<string> strings;

void gen(VI &path, int reg, int end) {
    if (reg == 6) {
        path.push_back(end);

        if (path.size() == 2 and path.front() == path.back())
            ;
        else {
            allpaths.push_back(path);
        }
        path.pop_back();
        return;
    }

    gen(path, reg + 1, end);

    if (reg != path.front() and reg != end) {
        path.push_back(reg);
        gen(path, reg + 1, end);
        path.pop_back();
    }
}

void solve() {
    string s;
    int n;
    cin >> n;
    getline(cin, s);

    const int base = 1870, end = 2004;
    const int totalcnt = end - base + 1;

    vector<VVI> movieslist(totalcnt, VVI(6));

    for (int i = 0; i < n; i++) {
        int year, reg;
        getline(cin, s);
        int len = s.size();
        reg = s.back() - '0';
        year = stoi(s.substr(len - 6, 4)) - base;
        s = s.substr(0, len - 7);

        strings.push_back(s);
        regions.push_back(reg);

        movieslist[year][reg].push_back(i);
    }

    // +1 for the default guy
    PII best[totalcnt + 1][6][6];

    for (int i = 0; i <= totalcnt; i++)
        for (int j = 1; j <= 5; j++)
            for (int k = 1; k <= 5; k++)
                best[i][j][k] = {0, 0};

    for (int year = totalcnt - 1; year >= 0; year--) {
        for (int have = 0; have <= 5; have++) {
            int i = -1;

            for (const auto &path : allpaths) {
                ++i;

                const int st = path.front(), swit = path.size() - 1;
                const int oth = path.back();
                if (swit > have)
                    continue;

                int val = 0;
                for (auto x : path)
                    val += movieslist[year][x].size();
                if (path.back() == path.front() and path.size() >= 2) {
                    val -= movieslist[year][path.back()].size();
                }

                val += best[year + 1][oth][have - swit].first;
                if (best[year][st][have].first < val) {
                    best[year][st][have] = {val, i};
                }
            }
        }
    }

    int reg = 0;
    for (int i = 1; i <= 5; i++) {
        if (best[0][i][5].first > best[0][reg][5].first)
            reg = i;
    }

    VI answer;
    int rem = 5;
    for (int i = 0; i < totalcnt; i++) {
        const int pathi = best[i][reg][rem].second;

        // cout << pathi << endl;
        const auto &path = allpaths[pathi];
        rem -= path.size() - 1;
        assert(rem >= 0);

        int j = -1;
        for (auto reg : path) {
            ++j;

            if (j != 0 and reg == path.front())
                continue;

            for (auto m : movieslist[i][reg])
                answer.push_back(m);
        }

        reg = path.back();
    }

    cout << answer.size() << "\n";
    for (auto x : answer)
        cout << strings[x] << " " << regions[x] << endl;
}

int main() {
    freopen("dvd.in", "r", stdin);
    freopen("dvd.out", "w", stdout);

    for (int i = 1; i <= 5; i++) {
        VI p = {i};
        allpaths.push_back(p);
        for (int j = 1; j <= 5; j++) {
            VI p = {i};
            gen(p, 1, j);
        }
    }
    // for (auto x : allpaths) {
    //     for (auto y : x) cout << y << " ";
    //     cout << endl;
    //     for (auto i = 0; i < x.size() - 1; i++) {
    //         // cout << i << " " << x[i] << " " << x[i + 1] << endl;
    //         assert(x[i] != x[i + 1]);
    //     }
    // }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // int t;cin >> t;while(t--)
    solve();
    return 0;
}
