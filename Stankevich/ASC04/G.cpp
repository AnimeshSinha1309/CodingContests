#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef long double ld;
typedef vector<ld> vld;
typedef vector<vld> vvld;

string names[101];
VVI teams(21);

void solve() {
    int n;
    cin >> n;
    getline(cin, names[0]);
    for (int i = 0; i < n; i++)
        getline(cin, names[i]);
    int m;
    cin >> m;

    VI pm(m);
    vvld score(m, vld(n, 0));
    VVI probsolved(m, VI(n, 0));
    VVI teamseen(m, VI(n, 0));
    VI numteams(m);
    vld totalscore(n, 0);
    VVI contests(n);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            teams[i].push_back(y - 1);
        }
        int probs;
        cin >> probs;
        int runs;
        cin >> runs;

        VVI attempts(n, VI(probs));
        VI totalpenalty(n, 0);

        for (int j = 0; j < runs; j++) {
            int team, time;
            char prob, status;
            cin >> team >> prob >> time >> status;

            prob -= 'A';

            // ignore once accepted
            if (attempts[team][prob] == -1)
                continue;

            if (not teamseen[i][team]) {
                teamseen[i][team] = 1;
                numteams[i]++;
                contests[team].push_back(i);
            }

            if (status == '-') {
                attempts[team][prob]++;
            } else {
                probsolved[i][team]++;
                totalpenalty[team] += attempts[team][prob] * 20;
                pm[i] = max(pm[i], probsolved[i][team]);

                attempts[team][prob] = -1;
            }
        }

        sort(teams[i].begin(), teams[i].end(),
             [&totalpenalty, &probsolved](auto a, auto b) {
                 return probsolved[a] > probsolved[b] or
                        (probsolved[a] == probsolved[b] and
                         totalpenalty[a] < totalpenalty[b]);
             });
        VI rank(n);
        int r = 1;
        rank[teams[i].front()] = 1;
        for (int j = 1; j < n; j++) {
            auto b = teams[i][i], a = teams[i][i - 1];
            if (probsolved[a] == probsolved[b] and
                totalpenalty[a] == totalpenalty[b]) {
                rank[b] = r;
            } else
                rank[b] = ++r;
        }

        for (int j = 0; j < n; j++) {
            ld rawscore = pm[i] ? probsolved[i][j] / (ld)pm[i] : 0;
            auto k = numteams[i];
            auto b = k - 2;
            auto a = k + b;

            score[i][j] = rawscore * a / (rank[j] + b);
        }
    }

    for (int i = 0; i < n; i++) {
        if (contests[i].empty())
            continue;
        for (auto j : contests[i]) {
            totalscore[i] += score[i][j];
        }
        totalscore[i] /= contests[i].size();
    }

    VI people;
    iota(people.begin(), people.end(), 0);
    sort(people.begin(), people.end(), [&totalscore](auto a, auto b) {
        return totalscore[a] > totalscore[b];
    });
    unsigned long len = 0;
    for (auto name : names) {
        len = max(name.size(), len);
    }
    for (auto i : people) {
        string s;
        cout << names[i];
        for (int i = names[i].size(); i < len + 1l, i++) {
            cout << ' ';
        }
        cout << fixed << setprecision(4) << totalscore[i] << endl;
    }
}

int main() {
    // freopen("ranking.in", "r", stdin);
    // freopen("ranking.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
