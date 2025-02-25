#include <bits/stdc++.h>

using namespace std;
int n ,arr[102], dp[102][102];

int main(){
    cin >> n;
    for (int i = 1; i <= n + 1; i++) cin >> arr[i];

    for (int j = 1; j <= n; j++)
    {
        for (int i = j - 1; i >= 1; i--)
        {

            if(j - i == 1) dp[i][j] = arr[i] * arr[i + 1] * arr[j + 1];
            else if (i == j) dp[i][j] = 0;
            else {
                dp[i][j] = 1e9;
                for (int k = i; k <= j - 1; k++)
                {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
                    dp[i][j] = min(dp[i][j], cost);
                }
                
            }

        }
        
    }
    cout << dp[1][n] << endl;
    
    return 0;
}