#include <bits/stdc++.h>

using namespace std;
int n, mxn = -1001;
int arr[101][101], dp[101][101];

int main(){
    cin >> n;
    for (size_t i = 1; i <= n; i++) for (size_t j = 1; j <= i; j++) cin >> arr[i][j];
    if(n == 1) {
        cout << arr[1][1] << endl;
        return 0;
    }
    dp[1][1] = arr[1][1];
    for (size_t i = 2; i <= n; i++)
    {
        for (size_t j = 1; j <= i; j++)
        {
            if(i == j) dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
            else if (j == 1) dp[i][j] = dp[i - 1][j] + arr[i][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
            mxn = max(mxn, dp[i][j]);
        }
        
    }
    cout << mxn << endl;
    return 0;
}