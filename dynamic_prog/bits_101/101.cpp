#include <bits/stdc++.h>

using namespace std;
const int MOD = 100000007;
long long dp[10001];
long long bit(int n){
    if(n == 0) return 1;
    if(dp[n] != 0) return dp[n];

    int next = (bit(n - 1) % MOD + bit(n - 2)% MOD + bit(n - 4)% MOD )% MOD;
    dp[n] = next;
    return next;
}
int main(){
    long long n;
    cin >> n;
    // 1 2 4 7 12 21 37
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;
    // for (long long i = 4; i <= n; i++)
    // {
    //     dp[i] = (dp[(i - 1)%10001] % MOD + dp[(i - 2)%10001] % MOD + dp[(i - 4)%10001] % MOD) % MOD;
    // }
    cout << bit(n) << endl;
    return 0;
}
