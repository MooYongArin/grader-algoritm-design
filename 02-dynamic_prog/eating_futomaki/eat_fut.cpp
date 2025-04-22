#include <bits/stdc++.h>

using namespace std;
int n, a[5001], dp[5001][5001];
int eat(int l, int r){
    if(dp[l][r] != 0) return dp[l][r];
    if(l + 1 == r) {
        dp[l][r] = max(a[l], a[r]);
        return dp[l][r];
    }
    int cut_left = eat(l + 2, r) + max(a[l + 1], a[l]);
    int cut_right = eat(l, r - 2) + max(a[r - 1], a[r]);
    int cut_both = eat(l + 1, r - 1) + max(a[l], a[r]);

    dp[l][r] = max({cut_left, cut_right, cut_both});
    return dp[l][r];
}
int main(){
    cin >> n;
    for (size_t i = 1; i <= n; i++) cin >> a[i];
    
    cout << eat(1, n) << endl;
    
    return 0;
}