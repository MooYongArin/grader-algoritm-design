#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int arr[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) arr[i][j] = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
    }
    
    queue<pair<int, int>> q;
    vector<bool> visited(n, false);
    q.push({a, b});
    
    return 0;
}