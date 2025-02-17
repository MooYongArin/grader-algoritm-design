#include <bits/stdc++.h>

using namespace std;
int n, m, arr[21], dp[10001];
int main(){
    cin >> n >> m;

    for (size_t i = 1; i <= n; i++) cin >> arr[i];
    int sum = 0, cnt = 0;
    dp[1] = arr[1];
    for (size_t i = 1; i <= m; i++)
    {
        dp[i] = min(dp[i - 1] + 1, dp[i - 5] + 1);
        sum += arr[i];
    }
    cout << dp[m] << endl;
    
    
    return 0;
}