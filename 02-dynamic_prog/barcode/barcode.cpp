#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int dp[31][31][31]; // dp[length][consecutive][color][changes]

int countBarcodes(int length, int consecutive, int changes) {
    if (length == n) {
        return (changes == k) ? 1 : 0;
    }
    if (dp[length][consecutive][changes] != -1) {
        return dp[length][consecutive][changes];
    }

    int result = 0;
    if (consecutive < m) {
        // gen same number
        result += countBarcodes(length + 1, consecutive + 1, changes);
    }
    // gen different number
    result += countBarcodes(length + 1, 1, changes + 1);

    dp[length][consecutive][changes] = result;

    return dp[length][consecutive][changes];
}

int main() {
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    cout << countBarcodes(1, 1, 0) << endl;
    return 0;
}