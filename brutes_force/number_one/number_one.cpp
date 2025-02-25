#include <bits/stdc++.h>
using namespace std;

long long countOnes(long long n, long long l, long long r, long long start, long long end) {
    if (l > end || r < start) {
        return 0; // Out of range
    }
    if (n == 0) {
        return 0; // No 1s in the sequence
    }
    if (n == 1) {
        return max(0LL, min(r, end) - max(l, start) + 1); // All 1s in the range
    }

    long long mid = (start + end) / 2;
    long long left_count = countOnes(n / 2, l, r, start, mid - 1);
    long long right_count = countOnes(n / 2, l, r, mid + 1, end);
    long long mid_count = (l <= mid && mid <= r) ? n % 2 : 0;

    return left_count + mid_count + right_count;
}

int main() {
    long long n, l, r;
    cin >> n >> l >> r;

    long long length = 1;
    long long temp = n;
    while (temp > 1) {
        length = 2 * length + 1;
        temp /= 2;
    }

    cout << countOnes(n, l, r, 1, length) << endl;

    return 0;
}