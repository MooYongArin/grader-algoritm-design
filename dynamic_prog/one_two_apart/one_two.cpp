#include <iostream>
#include <vector>
using namespace std;

const int MOD = 100000007;
int dp[1000001];
int main() {
    int n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 3;
    dp[2] = 7;
    dp[3] = 15;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = (2 * dp[i - 1] % MOD + dp[i - 3] % MOD) % MOD;
    }
    
    cout << dp[n] << "\n";
    return 0;
}
