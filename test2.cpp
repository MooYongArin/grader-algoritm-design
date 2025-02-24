#include <bits/stdc++.h>
using namespace std;

int dp[31][31][31];
int recur(int i, int curr_m, int curr_k, int m, int k, int n) {
    // 2 กรณี 
    // ถ้า m เกิน เหลือ 1 กรณี : เปลี่ยน bit เท่านั้น
    // ถ้า k เกิน เหลือ 1 กรณี : bit เดิม
    // ถ้า i = n : return
    if (i == n) return (curr_k == k) ? 1 : 0;

    if(dp[i][curr_m][curr_k] != -1) return dp[i][curr_m][curr_k];
    
    
    if (curr_m >= m && curr_k < k) {
        return dp[i][curr_m][curr_k] = recur(i+1, 1, curr_k+1, m, k, n);
    }
    if (curr_m < m && curr_k >= k) {
        return dp[i][curr_m][curr_k] = recur(i+1, curr_m+1, curr_k, m, k, n);
    }
    if (curr_m < m && curr_k < k) {
        return dp[i][curr_m][curr_k] = recur(i+1, 1, curr_k+1, m, k, n) + recur(i+1, curr_m+1, curr_k, m, k, n);
    } 
}

int main() {
    int n, m, k;
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    cout << recur(1, 1, 0, m, k, n);
}

