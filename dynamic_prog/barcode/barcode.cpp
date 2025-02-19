#include <bits/stdc++.h>

using namespace std;
int n, m ,K, dp[31][31][31];
int main(){
    cin >> n >> m >> K;

    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
        for (int k = 0; k <= K; k++)
            {
                if(k <= i) dp[i][j][k] = 0;
                else if (j == 1) dp[i][j][k] = 1;
                else dp[i][j][k] = (2 * dp[i - 1][j][k]) ;
            }
        }
    }
    cout << dp[n][m][K] << endl;
    
    return 0;
}