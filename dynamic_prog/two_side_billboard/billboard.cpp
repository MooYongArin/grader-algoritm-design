#include <bits/stdc++.h>

using namespace std;
int n, w, k, l[200001], r[200001], dp[200001][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> w >> k;
    for (size_t i = 1; i <= n; i++) cin >> l[i];
    for (size_t i = 1; i <= n; i++) cin >> r[i];

    // 0 left, 1 right
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i - w - 1][1] + l[i], dp[i - 1][0]);
        dp[i][1] = max(dp[i - w - 1][0] + r[i], dp[i - 1][1]);
    }
    cout << max(dp[n][0], dp[n][1]);
    return 0;
}