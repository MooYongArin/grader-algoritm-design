#include <bits/stdc++.h>

using namespace std;
const int mod = 1997;
int n, k, dp[501][501];
int main(){
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
        dp[i][i] = 1;
    }
    for (int j = 2; j <= k; j++)
    {
        
        for (int i = j + 1; i <= n; i++)
        {
            dp[i][j] = (dp[i - 1][j - 1] % mod + (dp[i - 1][j] * j)  % mod)  % mod;
        }
        
    }
    cout << dp[n][k] << endl;
    return 0;
}