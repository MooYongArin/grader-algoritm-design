#include <bits/stdc++.h>

using namespace std;
const int MOD = 100000007;
long long dp[1000001], n;
int main(){
    cin >> n;
    dp[1] = 3;
    dp[2] = 7;
    for (size_t i = 3; i <= n; i++)
    {
        dp[i] = (2 * (dp[i - 1] % MOD) + (dp[i - 2] % MOD)) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}