#include <bits/stdc++.h>
using namespace std;
int dp[502][502];
string a, b;
int lcs(int n, int m){
    if(n < 0 || m < 0) return 0;
    if(dp[n][m] != 0) return dp[n][m];
    if(a[n] == b[m]) dp[n][m] = lcs(n - 1, m - 1) + 1;
    else dp[n][m] = max(lcs(n - 1, m), lcs(n, m-1));
    return dp[n][m];
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin >> a >> b;
    cout << lcs(a.length() - 1, b.length() - 1) << endl;
    return 0;
}