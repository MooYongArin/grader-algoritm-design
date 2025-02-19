#include <bits/stdc++.h>

using namespace std;
int r, c, dp[1001][1001];
char grid[1001][1001];
int maxK = 1;
int main(){
    cin >> r >> c;
    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) {
        if(j == 1) {
            cin >> grid[i][j];
            dp[i][j] = grid[i][j] - '0';
        }
        else {
            cin >> grid[i][j];
            if(grid[i][j - 1] != '0' && grid[i][j] == '1') dp[i][j] = dp[i][j - 1] + 1;
            else dp[i][j] = grid[i][j] - '0';
        }
        if(grid[i][j] == '1') maxK = 1; // atleast 1's 1
    }
    int makeSquare = 0, repeat_ones = 0;
    for (int j = 1; j <= c; j++) {
        for (int i = 2; i <= r; i++) {
            if(dp[i][j] != 0 && dp[i - 1][j] != 0){
                if(dp[i][j] <= dp[i - 1][j]) makeSquare = min(dp[i - 1][j], dp[i][j]);
            } 
            maxK = max(maxK, makeSquare);
        }
    }
    cout << maxK << endl;
    // for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) cout << grid[i][j];
    return 0;
}