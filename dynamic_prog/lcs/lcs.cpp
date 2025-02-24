#include <bits/stdc++.h>

using namespace std;
string s1, s2;
int dp[502][502];
int lcs() {
    int n = s1.size();
    int m = s2.size();

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}
int main(){
    cin >> s1 >> s2;
    cout << lcs() << endl;
    return 0;
}