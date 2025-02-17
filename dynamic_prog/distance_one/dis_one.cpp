#include <bits/stdc++.h>

using namespace std;
const int MAGIC_NUM = 100000007;
int k;
long long dp[5000];

int main(){
    int n;
    cin >> n >> k;

    for (size_t i = 1; i <= k; i++)
    {
        dp[i] = 1;
    }
    
    for (size_t i = k + 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - k - 1];
    }
    
    cout << dp[n] % MAGIC_NUM << endl;
    return 0;
}