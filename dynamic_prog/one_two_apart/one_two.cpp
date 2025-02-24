#include <iostream>
#include <vector>
using namespace std;

const int MOD = 100000007;
int dp[1000001], two[1000001], one[1000001];
int main() {
    int n;
    cin >> n;
    dp[1] = 3;
    two[1] = 1;
    one[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (3 * dp[i - 1]) % MOD;
        two[i] = dp[i - 1];
        one[i] = dp[i - 1];

        for (int j = 1; j <= 2 && i - j >= 0; j++)
        {
            dp[i] = (dp[i] % MOD - two[i - j] % MOD - one[i - j] % MOD + 2 * MOD) % MOD;
            two[i] = (two[i] % MOD - two[i - j] % MOD + MOD) % MOD;
            one[i] = (one[i] % MOD - one[i - j] % MOD + MOD) % MOD;
        }
    }
    
    cout << dp[n] << "\n";
    return 0;
}
