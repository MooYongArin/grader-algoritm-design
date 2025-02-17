#include <bits/stdc++.h>

using namespace std;
int n, c[10001], dp[10001];
int main(){
    cin >> n;
    for (size_t i = 1; i <= n; i++) cin >> c[i];

    dp[1] = c[1];
    for (size_t i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 3] + c[i]);
    }
    cout << dp[n] << endl;
    return 0;
}