// TODO: Solved using Editorial, Try Again

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(unsigned long n) {
    for (unsigned long i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

long long modPower(long long a, long long b, long long MOD) {
    long long cumulative = a, result = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1) result = (result * cumulative) % MOD;
        cumulative = (cumulative * cumulative) % MOD;
    } return result;
}
long long modInverse(long long a, long long MOD) {
    return modPower(a, MOD-2, MOD);
}

int main() {
    unsigned int n; cin >> n;
    if (n == 4) {
        cout << "YES" << endl << 1 << endl << 3 << endl << 2 << endl << 4 << endl;
    } else if (n == 1) {
        cout << "YES" << endl << 1 << endl;
    } else if (isPrime(n)) {
        cout << "YES" << endl; cout << 1 << endl;
        for (int i = 2; i < n; i++) cout << (i * modInverse(i-1, n)) % n << endl;
        cout << n << endl;
    } else {
        cout << "NO" << endl;
    }
}