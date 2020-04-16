#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests, b;
    cin >> tests >> b;
    for (int test = 1; test <= tests; test++) {
        string s(b, 'X');
        for (int i = 0, q = 1; i < b; i++, q++) {
            cout << i + 1 << endl;
            char res;
            cin >> res;
            s[i] = res;
            if (q % 10 == 1)
                i--;
        }
		reverse(s.begin(), s.end());
        cout << s << endl;
        char res;
        cin >> res;
        if (res != 'Y')
            exit(1);
    }
}
