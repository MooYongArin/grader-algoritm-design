#include <bits/stdc++.h>

using namespace std;
int a[1001][1001], p[1001][1001], n, m, k;
int main(){
    int r1, r2, c1, c2;
    cin >> n >> m >> k;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            cin >> a[i][j];

    p[0][0] = a[0][0];
    for (size_t i = 0; i < m; i++) p[0][i] = p[0][i-1] + a[0][i];

    for (size_t i = 0; i < n; i++)
    {
        p[i][0] = p[i-1][0] + a[i][0];

        for (size_t j = 0; j < m; j++)  
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i][j];
    }
    
    for (size_t i = 0; i < k; i++)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << p[r2][c2] - p[r1 - 1][c2] - p[r2][c1 - 1] + p[r1 - 1][c1 - 1] << endl;
    }
    
    return 0;
}