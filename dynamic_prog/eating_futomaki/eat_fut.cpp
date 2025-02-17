#include <bits/stdc++.h>

using namespace std;
int n, a[5001], cut[5001][5001];
int main(){
    cin >> n;
    for (size_t i = 1; i <= n; i++) cin >> a[i];
    
    for (int sz = 2; sz <= n; sz++) {
        for (int l = 1, r = sz; r <= n; l++, r++) {
            cut[l][r] = max({
                    cut[l+2][r] + max(a[l], a[l + 1]),
                    cut[l+1][r-1] + max(a[l], a[r]),
                    cut[l][r-2] + max(a[r], a[r-1])});
        }
    }
    cout << cut[1][n] << endl;
    
    return 0;
}