#include <bits/stdc++.h>

using namespace std;
long long n, w, k, l[200001], r[200001], dp1[200001][2], dp[200001][2][51];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> w >> k;

    for (size_t i = 1; i <= n; i++) cin >> l[i];
    for (size_t i = 1; i <= n; i++) cin >> r[i];
    if (n != k)
    {
        // 0 left, 1 right
        dp1[1][0] = l[1];
        dp1[1][1] = r[1];
        for (int i = 2; i <= n; i++)
        {
            if(i - w - 1 >= 0 ){
                dp1[i][0] = max(dp1[i - w - 1][1] + l[i], dp1[i - 1][0]);
                dp1[i][1] = max(dp1[i - w - 1][0] + r[i], dp1[i - 1][1]);
            } else {
                dp1[i][0] = max(l[i], dp1[i - 1][0]);
                dp1[i][1] = max(r[i], dp1[i - 1][1]);
            }
        }
        cout << max(dp1[n][0], dp1[n][1]) << endl;
        return 0;
    }
    
    // 0 left, 1 right
    dp[0][0][0] = dp[0][1][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - w - 1 >= 0)
            {
                dp[i][0][j] = max(dp[i - w - 1][1][j - 1] + l[i], dp[i - 1][0][j]);
                dp[i][1][j] = max(dp[i - w - 1][0][j - 1] + r[i], dp[i - 1][1][j]);
            }
            else
            {
                dp[i][0][j] = max(l[i], dp[i - 1][0][j]);
                dp[i][1][j] = max(r[i], dp[i - 1][1][j]);
            }
        }
    }
    long long result = 0;
    for (int j = 1; j <= k; j++) {
        result = max({result, dp[n][0][j], dp[n][1][j]});
    }
    cout << result << endl;
    return 0;

    return 0;
}