#include <bits/stdc++.h>

using namespace std;
const int mod = 1000003;
int n, k, s[11], dp[10001];
int main(){
    cin >> n >> k;
    for (size_t i = 1; i <= k; i++) cin >> s[i];
    dp[0] = 1;
    dp[1] = 1;
    for (size_t i = 2; i <= n; i++)
    {
        for (size_t j = 1; j <= k; j++)
        {
            if(i >= s[j]) dp[i] += dp[i - s[j]] % mod;
        }
        dp[i] %= mod;
    }

    cout << dp[n] << endl;
    return 0;
}