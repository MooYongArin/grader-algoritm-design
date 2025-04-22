#include <bits/stdc++.h>

using namespace std;
int n, a[5001], dp[5001][5001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 2; i <= n; i++) {
        for (int l = 1; l <= n - i + 1; l++) {
            int r = l + i - 1;
            for (int i = l; i < r; i++) {
                dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][r]);
            }
            dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + a[l] * a[r]);
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}