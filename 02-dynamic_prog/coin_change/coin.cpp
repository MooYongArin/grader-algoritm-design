#include <bits/stdc++.h>

using namespace std;
int n, m, arr[21], dp[10001];
int main(){
    cin >> n >> m;

    for (size_t i = 1; i <= n; i++) cin >> arr[i];
    dp[0] = 0;
    dp[1] = 1;
    for (size_t i = 2; i <= m; i++)
    {
        int minN = 10001;
        for (size_t j = 1; j <= n; j++)
        {
            // cout << arr[j] << " ";
            if(i >= arr[j]) minN = min(dp[i - arr[j]] + 1, minN);
        }
        dp[i] = minN;
    }
    cout << dp[m] << endl;
    
    
    return 0;
}