#include <bits/stdc++.h>

using namespace std;
const int MOD = 100000007;
int dp[1000001];
int main(){
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 3;
    dp[2] = 7;
    dp[3] = 14 + 1;
    dp[4] = 30 + 3;

    for (size_t i = 5; i <= n; i++)
    {
        dp[i] = ((dp[i - 1]*2) % MOD + dp[i - 3] % MOD) % MOD;
    }
    
    cout << dp[n] << endl;
    return 0;
}