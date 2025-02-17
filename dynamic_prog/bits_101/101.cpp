#include <bits/stdc++.h>

using namespace std;
const int MOD = 100000007;
long long dp[10001];
int main(){
    int n;
    cin >> n;
    // 1 2 4 7 12 21 37
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD + dp[i - 4] % MOD) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}
