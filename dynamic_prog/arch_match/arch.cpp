#include <bits/stdc++.h>

using namespace std;
int n, a[5001], dp[5001][5001];
int arch(int l, int r){
    if(dp[l][r] != 0) return dp[l][r];
    if(l == r) {
        dp[l][r] = a[l];
        return a[l];
    }
    if(l + 1 == r) {
        dp[l][r] = a[l] * a[r];
        return dp[l][r];
    }
    // int left_out = arch(l + 1, r) + arch(1, l);
    // int right_out = arch(l, r - 1) + arch(r, n);
    int sel_both = arch(l + 1, r - 1) + arch(1, l) + arch(r, n);
    // cout << left_out << " " << right_out << endl;
    // dp[l][r] = max({left_out, right_out, sel_both});
    dp[l][r] = sel_both;
    return dp[l][r];
}
int main(){
    cin >> n;
    for (size_t i = 1; i <= n; i++) cin >> a[i];
    
    cout << arch(1, n) << endl;
    
    return 0;
}