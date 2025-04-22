#include <bits/stdc++.h>

using namespace std;
int n, k, a[5002], b[5002], dp[5002];
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= k; i++) cin >> b[i];

    dp[0] = 0;
    dp[1] = a[1];
    for(int i = 2; i <= n; i++) {
        int maxN = INT_MIN;
        for (int j = 1; j <= k; j++)
        {
            if(i - j >= 1) maxN = max(dp[i - j] + a[i] - b[j], maxN);

        }
        dp[i] = maxN;
    }

    cout << dp[n] << endl;
    return 0;
}