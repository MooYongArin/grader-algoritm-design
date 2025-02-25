#include <bits/stdc++.h>

using namespace std;
int n, m, a[12], dp[12][10002];
int exchange(int q, int w){
    return (q - w) * (q - w);
}
int main(){
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i - 1][j] != -1) {
                for (int k = 1; k <= 100; k++) {
                    int new_area = j + k * k;
                    if (new_area <= m) {
                        int cost = dp[i - 1][j] + exchange(a[i], k);
                        if (dp[i][new_area] == -1 || dp[i][new_area] > cost) {
                            dp[i][new_area] = cost;
                        }
                    }
                }
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}