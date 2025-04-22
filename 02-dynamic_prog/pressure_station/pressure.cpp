#include <bits/stdc++.h>

using namespace std;
int n, k, p[10001], dp[10001];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> p[i];

    fill(dp, dp + n + 1, INT_MAX);
    dp[0] = 0; 

    for (int i = 1; i <= n; i++) {
        for (int j = max(1, i - k); j <= min(n, i + k); j++) {
            dp[j] = min(dp[j], dp[max(0, i - k - 1)] + p[i]);
        }
    }

    cout << dp[n] << endl;
    return 0;
}