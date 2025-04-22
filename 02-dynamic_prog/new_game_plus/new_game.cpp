#include <bits/stdc++.h>

using namespace std;
const int mod = 100000007;
int room[502][502], dp[502][502][3];
int main(){
    int r, c;
    cin >> r >> c;

    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) cin >> room[i][j];
    // (0 = X, 1 = Y, 2 = Z)
    for (int i = 1; i <= r; i++) if(room[i][1] == 0) dp[i][1][1] = 1;
    for (int i = 1; i <= r; i++) if(room[i][2] == 0) {
        if(dp[i - 1][1][1] != 0) dp[i][2][2] = 1;
        if(dp[i][1][1] != 0) dp[i][2][1] = 1;
        if(dp[i + 1][1][1] != 0) dp[i][2][0] = 1;
    }
    // cout << dp[1][1][1];
    for (int j = 3; j <= c; j++) {
        for (int i = 1; i <= r; i++) {
            if (room[i][j] == 1) continue;
            dp[i][j][0] = (dp[i+1][j-1][1] % mod + dp[i+1][j-1][2] % mod) % mod;
            dp[i][j][1] = (dp[i][j-1][0] % mod + dp[i][j-1][2] % mod) % mod;
            dp[i][j][2] = (dp[i-1][j-1][0] % mod + dp[i-1][j-1][1] % mod) % mod;
        }
    }
    int sum = 0;
    for (int i = 1; i <= r; i++) sum = (sum % mod + dp[i][c][0] % mod + dp[i][c][1] % mod + dp[i][c][2] % mod) % mod;
    cout << sum << endl;
    return 0;
}