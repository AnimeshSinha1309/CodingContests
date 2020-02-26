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

template <class Type>
class Matrix {
   public:
    vector<vector<Type>> mat;
    unsigned long m, n = 0;

    Matrix(unsigned long size, bool unity = true) {
        mat = vector<vector<Type>>(size, vector<Type>(size, 0));
        m = size;
        n = size;
        if (unity)
            for (int i = 0; i < size; i++)
                mat[i][i] = 1;
    }
    Matrix(vector<vector<Type>> mat) {
        this->mat = mat;
        m = this->mat.size();
        n = (this->mat.size() > 0 ? this->mat[0].size() : 0);
    }
    friend Matrix<Type> operator*(Matrix<Type> a, Matrix<Type> b) {
        assert(a.m == b.n);
        Matrix res(vector<vector<long long>>(a.n, vector<long long>(b.m, 0)));
        for (int i = 0; i < a.n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < a.m; k++) {
                    res.mat[i][j] =
                        (res.mat[i][j] + (a.mat[i][k] * b.mat[k][j]));
                }
            }
        }
        return res;
    }
    friend vector<Type> operator*(Matrix<Type> a, vector<Type> b) {
        assert(a.m == b.size());
        vector<Type> res(a.n, 0);
        for (int i = 0; i < a.n; i++) {
            for (int j = 0; j < a.m; j++) {
                res[i] = (res[i] + (a.mat[i][j] * b[j]));
            }
        }
        return res;
    }
    friend Matrix<Type> operator^(Matrix<Type> a, long long b) {
        assert(a.n == a.m);
        Matrix<Type> cumulative = a, result = Matrix<long long>(a.n);
        for (; b > 0; b /= 2) {
            if (b % 2 == 1)
                result = (result * cumulative);
            cumulative = (cumulative * cumulative);
        }
        return result;
    }
};

struct Fraction {
    long long p, q;

    long long mod_power(long long a, long long b, long long m) {
        long long cumulative = a, result = 1;
        for (; b > 0; b /= 2) {
            if (b % 2 == 1)
                result = (result * cumulative) % m;
            cumulative = (cumulative * cumulative) % m;
        }
        return result;
    }

    Fraction(long long p, long long q) {
        long long gcd = 1;
        if (q != 0 && p != 0)
            for (long long a = abs(p), b = abs(q); b > 0;
                 gcd = b, b = a % b, a = gcd)
                ;
        this->p = p / gcd, this->q = q / gcd;
        if (this->q < 0)
            this->q *= -1, this->p *= -1;
    }

    friend Fraction operator+(Fraction a, Fraction b) {
        return {a.p * b.q + a.q * b.p, a.q * b.q};
    }
    friend Fraction operator-(Fraction a, Fraction b) {
        return {a.p * b.q - a.q * b.p, a.q * b.q};
    }
    friend Fraction operator*(Fraction a, Fraction b) {
        return {a.p * b.p, a.q * b.q};
    }
    friend Fraction operator/(Fraction a, Fraction b) {
        return {a.p * b.q, a.q * b.p};
    }
    friend long long operator%(Fraction &x, long long y) {
        return ((x.p % y) * mod_power(x.q, y - 2, y)) % y;
    }
    friend Fraction operator^(Fraction a, long long power) {
        return {a.p ^ power, a.q ^ power};
    }
    friend bool operator<(Fraction a, Fraction b) {
        return a.p * b.q < a.q * b.p;
    }
    friend bool operator<=(Fraction a, Fraction b) {
        return a.p * b.q <= a.q * b.p;
    }
    friend bool operator>(Fraction a, Fraction b) {
        return a.p * b.q > a.q * b.p;
    }
    friend bool operator>=(Fraction a, Fraction b) {
        return a.p * b.q >= a.q * b.p;
    }
    friend bool operator==(Fraction a, Fraction b) {
        return a.p * b.q == a.q * b.p;
    }
    friend bool operator!=(Fraction a, Fraction b) {
        return a.p * b.q != a.q * b.p;
    }
    static Fraction slope(pair<long long, long long> &pt1,
                          pair<long long, long long> &pt2) {
        return {pt1.second - pt2.second, pt1.first - pt2.first};
    }
    long double decimal() {
        return (long double)this->p / (long double)this->q;
    }
};

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    ll n, k, a1, a2, b1, b2;
    cin >> n >> k >> a1 >> a2 >> b1 >> b2;
    a1--, b1--, a2--, b2--;
    ll machine[n];
    vector<ll> input(n);
    iota(machine, machine + n, 0);
    iota(input.begin(), input.end(), 0);
    reverse(machine + a1, machine + a2 + 1);
    reverse(machine + b1, machine + b2 + 1);
    Matrix<ll> perm(n, false);
    for (int i = 0; i < n; i++)
        perm.mat[i][machine[i]] = 1;
    perm = perm ^ k;
    vll result = perm * input;
    for (int i = 0; i < n; i++)
        cout << result[i] + 1 << endl;
}