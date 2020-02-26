#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    string st; getline(cin, st);
    set<char> data;
    for (const auto &ch : st)
        if ('a' <= ch && ch <= 'z') data.insert(ch);
    cout << data.size();
}