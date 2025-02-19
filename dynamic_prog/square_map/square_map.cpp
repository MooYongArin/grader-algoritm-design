#include <bits/stdc++.h>
using namespace std;

int r, c, dp[1001][1001];
int main() {
    cin >> r >> c;
    int maxSize = 0;

    for (int i = 1; i <= r; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= c; j++) {
            if (row[j] == '1') {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                maxSize = max(maxSize, dp[i][j]);
            }
        }
    }

    cout << maxSize << endl;
    return 0;
}
