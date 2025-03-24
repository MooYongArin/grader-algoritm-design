#include <bits/stdc++.h>

using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);
    int n;
    cin >> n;
    int adj, deg[n], k = 0;
    fill(deg, deg + n, 0);
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cin >> adj;
            cnt += adj;
        }
        deg[cnt]++;
        k = max(k, cnt);
    }
    for (int i = 0; i <= k; i++) cout << deg[i] << " ";
    
    return 0;
}