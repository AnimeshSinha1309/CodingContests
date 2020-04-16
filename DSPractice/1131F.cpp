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

ll ans = 0;

long long _inv = 0;
pll result[(ll)1e5 + 1];

template <typename T>
void __merge(vector<T> arr, int start, int mid, int end) {
    ll i = start, j = mid, k = 0;
    vector<T> res(end - start);
    while (i < mid && j < end) {
        if (arr[i] < arr[j]) {
            res[k++] = arr[i++];
        } else {
            res[k++] = arr[j++];
        }
    }
    while (i < mid) {
        res[k++] = arr[i++];
    }
    while (j < end) {
        res[k++] = arr[j++];
    }
    for (ll i = start; i < end; i++) {
        arr[i] = res[i - start];
    }
}
template <typename T>
void merge_sort(vector<T> arr, int start = 0, int end = -1) {
    if (end == -1)
        end = arr.size();
    if (start >= end - 1)
        return;
    merge_sort(arr, start, (start + end) / 2);
    merge_sort(arr, (start + end) / 2, end);
    __merge<T>(arr, start, (start + end) / 2, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    vpl a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first;
    for (int i = 0; i < n; i++)
        cin >> a[i].second;

    sort(a.begin(), a.end(), [](pll x, pll y) { return x.second < y.second; });
    merge_sort(a, 0, a.size());

    cout << ans << endl;
}
