#include <bits/stdc++.h>

using namespace std;
const int MOD = 100000007;
long long dp[10001], one[10001], one_zero[10001];
long long bit(int i){
    if(dp[i] != 0) return dp[i];

    dp[i] = (2 * bit(i - 1)) % MOD;
    one[i] = (dp[i - 1] % MOD - one_zero[i - 1] % MOD + MOD) % MOD;
    one_zero[i] = one[i - 1] % MOD;

    dp[i] = (dp[i] % MOD - one_zero[i - 1] % MOD + MOD) % MOD;

    return dp[i];
}
int main(){
    long long n;
    cin >> n;
    // 1 2 4 7 12 21 37

    dp[1] = 2;
    one[1] = 1;
    one_zero[1] = 0;
    dp[2] = 4;
    one[2] = 2;
    one_zero[2] = 1;
    cout << bit(n) << endl;
    return 0;
}

