#include <bits/stdc++.h>

using namespace std;
int n, m, arr[501][501], dp[501][501];
int main(){
    cin >> n >> m;
    for (size_t i = 1; i <= n; i++) for (size_t j = 1; j <= m; j++) cin >> arr[i][j];
    int mxN = arr[1][1];
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= m; j++) {
            if(i == 1) dp[i][j] = dp[i][j - 1] + arr[i][j];
            else if (j == 1) dp[i][j] = dp[i - 1][j] + arr[i][j];
            else {
                if(dp[i - 1][j - 1] + arr[i][j] > dp[i - 1][j] && dp[i - 1][j - 1] + arr[i][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 2 * arr[i][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
            }
            mxN = max(mxN, dp[i][j]);
        }
    }
    cout << mxN << endl;
    return 0;
}