#include <bits/stdc++.h>

using namespace std;
int n ,arr[102], dp[102][102], minCost = 1e10;
int main(){
    cin >> n;
    ++n;
    for (size_t i = 1; i <= n; i++) cin >> arr[i];

    for (size_t j = 1; j <= n; j++)
    {
        for (size_t i = 1; i <= j; i++)
        {
            if(j - i == 1) dp[i][j] = arr[i] * arr[i + 1] * arr[j];
        }
        
    }
    
    
    return 0;
}