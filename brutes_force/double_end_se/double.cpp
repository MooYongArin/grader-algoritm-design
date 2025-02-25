#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; 
    cin >> n;

    int maxN = -1e9;
    unordered_map<int, int> dp;
    for(int i = 0; i < n; ++i){
        cin >> x;
        if (dp.find(x) != dp.end()) {
            dp[x] = max(dp[x] + x, x);
        } else {
            dp[x] = x;
        }
        maxN = max(maxN, dp[x]);
    }

    cout << maxN;
    
}

