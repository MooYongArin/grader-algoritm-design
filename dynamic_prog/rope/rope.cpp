#include <bits/stdc++.h>

using namespace std;
int n, a, b, c;
int dp[4001];

int main(){
    cin >> n >> a >> b >> c;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int maxN = -1;
        if(i - a >= 0 && dp[i - a] != -1) maxN = max(maxN, dp[i - a] + 1);
        if(i - b >= 0 && dp[i - b] != -1) maxN = max(maxN, dp[i - b] + 1);
        if(i - c >= 0 && dp[i - c] != -1) maxN = max(maxN, dp[i - c] + 1);
        dp[i] = maxN;
    }
    cout << dp[n] << endl;
    return 0;
}
