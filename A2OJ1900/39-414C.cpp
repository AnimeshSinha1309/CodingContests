#include <cstdio>

long long inversionsF[(1 << 21)], inversionsB[(1 << 21)];
int input[1 << 21];
void _merge(int *A, int start, int mid, int end, int pos) {
    int result[end - start];
    for (int xF = start, yF = mid, xB = start, yB = mid;
         xF < mid || yF < end;) {
        if (xF < mid && (yF >= end || A[xF] <= A[yF])) {
            result[xF + yF - start - mid] = A[xF];
            xF++;
        } else {
            result[xF + yF - start - mid] = A[yF];
            yF++;
            inversionsF[pos] += mid - xF;
        }
        if (xB < mid && (yB >= end || A[xB] < A[yB])) {
            xB++;
        } else {
            yB++;
            inversionsB[pos] += xB - start;
        }
    }
    for (int i = start; i < end; i++)
        A[i] = result[i - start];
}
void sort(int *A, int start, int end, int pos) {
    if (start >= end - 1)
        return;
    sort(A, start, (start + end) / 2, 2 * pos);
    sort(A, (start + end) / 2, end, 2 * pos + 1);
    _merge(A, start, (start + end) / 2, end, pos);
}

int main() {
    // Take the input and count the inversions
    int n;
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); i++)
        scanf("%d", input + i);
    sort(input, 0, 1u << n, 1);
    // Stack them up as layers based on the levels
    long long invLayerF[n + 1], invLayerB[n + 1];
    for (int l = 1, r = 2, layer = 0; layer <= n;
         l = 2 * l, r = 2 * r, layer++) {
        invLayerF[layer] = 0;
        invLayerB[layer] = 0;
        for (int i = l; i < r; i++)
            invLayerF[layer] += inversionsF[i];
        for (int i = l; i < r; i++)
            invLayerB[layer] += inversionsB[i];
    }
    // Process the queries by inverting the levels and recomputing the total
    int m;
    scanf("%d", &m);
    long long current[n + 1];
    for (int i = 0; i <= n; i++)
        current[i] = invLayerF[i];
    for (int i = 0; i < m; i++) {
        int q;
        scanf("%d", &q);
        q = n - q;
        for (int j = q; j <= n; j++)
            current[j] = (invLayerF[j] + invLayerB[j]) - current[j];
        long long result = 0;
        for (int j = 0; j <= n; j++)
            result += current[j];
        printf("%lld\n", result);
    }
}