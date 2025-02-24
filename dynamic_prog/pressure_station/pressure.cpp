#include <bits/stdc++.h>

using namespace std;
int n, k, p[10001], dp[10001];
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> p[i];

    for (int i = 1; i <= n; i++) {
        for (int j = -k; j <= k && i + j > 0; j++)
        {
            if(i - k - 1 > 0) {
                if(dp[i + j] != 0) dp[i + j] = min(dp[i + j], p[i] + dp[i - k - 1]);
                else dp[i + j] = p[i] + dp[i - k - 1];
            } else {
                if(dp[i + j] != 0) dp[i + j] = min(dp[i + j], p[i] + dp[0]);
                else dp[i + j] = p[i] + dp[0];
            }
        }
        
    }

    cout << dp[n] << endl;
    return 0;
}