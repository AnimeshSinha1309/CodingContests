#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef pair<long long, long long> pll;
#define minimize(var, val) (var = min((val), var))
const long long MOD = 1e9 + 7;

template <typename Type>
class Matrix {
   public:
    long long rows, cols;
    vector<vector<Type>> mat;

    Matrix(long long n, bool identity = true) {
        this->rows = n;
        this->cols = n;
        mat = vector<vector<Type>>(n, vector<Type>(n, 0));
        if (identity) {
            for (int i = 0; i < this->rows; i++)
                mat[i][i] = 1;
        }
    }
    Matrix(long long n, long long m) {
        this->rows = n;
        this->cols = m;
        mat = vector<vector<Type>>(n, vector<Type>(m, 0));
    }
    Matrix(vector<vector<Type>> m) {
        this->rows = m.size();
        this->cols = rows > 0 ? m[0].size() : 0;
        this->mat = m;
    }
    friend vector<Type> operator*(Matrix<Type> x, vector<Type> y) {
        vector<Type> res(y.size());
        assert(x.cols == y.size());
        for (int i = 0; i < x.cols; i++) {
            for (int j = 0; j < x.rows; j++) {
                res[i] = x[i][j] * y[j];
            }
        }
        return res;
    }
    friend Matrix<Type> operator*(Matrix<Type> x, Matrix<Type> y) {
        assert(x.cols == y.rows);
        Matrix res(x.rows, y.cols);
        for (int i = 0; i < x.rows; i++) {
            for (int j = 0; j < y.cols; j++) {
                for (int k = 0; k < x.cols; k++) {
                    res.mat[i][j] =
                        (res.mat[i][j] + x.mat[i][k] * y.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }
    friend Matrix<Type> operator^(Matrix<Type> mat, long long pow) {
        Matrix<Type> cumulative = mat, result(mat.rows, true);
        for (; pow > 0; pow /= 2) {
            if (pow & 1)
                result = result * cumulative;
            cumulative = cumulative * cumulative;
        }
        return result;
    }
};

int main() {
    ll n, k;
    cin >> n >> k;
    Matrix<ll> dp(n, false);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dp.mat[i][j];
    dp = dp ^ k;
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = (ans + dp.mat[i][j]) % MOD;
    cout << ans << endl;
}