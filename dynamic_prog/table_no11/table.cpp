#include <bits/stdc++.h>

using namespace std;
const int MOD = 100000007;
long long dp[1000001], n;
int main(){
    cin >> n;
    dp[2] = 7;
    dp[3] = 17;
    for (size_t i = 4; i <= n; i++)
    {
        dp[i] = (2 * (dp[i - 1] % MOD) + (dp[i - 2] % MOD)) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}