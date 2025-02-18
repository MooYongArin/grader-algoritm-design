#include <bits/stdc++.h>

using namespace std;
int n, m, w[501], v[501], dp[501][501], arr[501][501];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> w[i];

    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) cin >> arr[i][j];
    int i = n + 1, j = m + 1;
    
    
    return 0;
}