#include <bits/stdc++.h>

using namespace std;
int n, m, w[501], v[501], arr[501][501];
vector<int> res;
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> w[i];

    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) cin >> arr[i][j];
    
    int a = n, b = m;
    while (arr[a][b] != 0 && a > 0 && b > 0) {
        if (arr[a][b] != arr[a-1][b]) {
            res.push_back(a);
            b -= w[a];
        }
        a--;
    }
    
    cout << res.size() << endl;
    for (int &idx : res) {
        cout << idx << " ";
    }
    
    return 0;
}