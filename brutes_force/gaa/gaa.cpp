#include <bits/stdc++.h>

using namespace std;

char findCharacter(long long N, long long k, long long length) {
    if (k == 0) {
        if (N == 1) return 'g';
        else return 'a';
    }

    long long prev_length = (length - (k + 3)) / 2;
    if (N <= prev_length) {
        return findCharacter(N, k - 1, prev_length);
    } else if (N > prev_length + k + 3) {
        return findCharacter(N - (prev_length + k + 3), k - 1, prev_length);
    } else {
        if (N == prev_length + 1) return 'g';
        else return 'a';
    }
}

int main() {
    long long N;
    cin >> N;

    long long k = 0;
    long long length = 3; // Length of G(0)

    while (length < N) {
        k++;
        length = 2 * length + (k + 3);
    }

    cout << findCharacter(N, k, length) << endl;

    return 0;
}