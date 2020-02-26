#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#define MOD 1000000007
#define PHI 1000000006

using namespace std;

template <class Type>
class Matrix {
   public:
    vector<vector<Type>> mat;
    unsigned long m, n = 0;

    Matrix(unsigned long size) {
        mat = vector<vector<Type>>(size, vector<Type>(size, 0));
        m = size;
        n = size;
        for (int j = 0; j < n; j++)
            mat[j][j] = 1;
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
                        (res.mat[i][j] + (a.mat[i][k] * b.mat[k][j])) % PHI;
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
                res[i] = (res[i] + (a.mat[i][j] * b[j])) % PHI;
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

long long modPower(long long a, long long b) {
    long long cumulative = a, result = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            result = (result * cumulative) % MOD;
        cumulative = (cumulative * cumulative) % MOD;
    }
    return result;
}

int main() {
    long long n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    Matrix<long long> opF({
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 1},
    });
    Matrix<long long> opC({{1, 0, 0, 0, 0},
                           {1, 1, 0, 0, 0},
                           {0, 0, 0, 1, 0},
                           {0, 0, 0, 0, 1},
                           {0, 1, 1, 1, 1}});
    vector<long long> inF = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<long long> inC = {2, 2, 0, 0, 0};
    vector<long long> rsF = (opF ^ (n - 3)) * inF;
    vector<long long> rsC = (opC ^ (n - 3)) * inC;
    long long resC = modPower(c, rsC[4] % MOD);
    long long resF1 = modPower(f1, rsF[6] % MOD);
    long long resF2 = modPower(f2, rsF[7] % MOD);
    long long resF3 = modPower(f3, rsF[8] % MOD);
    cout << (((resF1 * resF2) % MOD) * ((resF3 * resC) % MOD)) % MOD << endl;
}