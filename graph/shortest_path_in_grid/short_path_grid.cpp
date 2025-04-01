#include <bits/stdc++.h>

using namespace std;
int main(){
    int r, c;
    cin >> r >> c;
    char arr[r][c];
    bool visited[r][c];
    int dist[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            visited[i][j] = false;
            dist[i][j] = -1;
        }
    }

    
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    dist[0][0] = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int a = p.first, b = p.second;
        if(arr[a + 1][b] == '.' && !visited[a + 1][b] && a + 1 < r) {
            q.push({a+1, b});
            dist[a+1][b] = dist[a][b] + 1;
            visited[a + 1][b] = true;
        }
        if(arr[a][b + 1] == '.' && !visited[a][b + 1] && b + 1 < c) {
            q.push({a, b + 1});
            dist[a][b+1] = dist[a][b] + 1;
            visited[a][b + 1] = true;
            // cout << "down ";
        }
        if(arr[a - 1][b] == '.' && !visited[a - 1][b] && a - 1 >= 0) {
            q.push({a - 1, b});
            dist[a-1][b] = dist[a][b] + 1;
            visited[a - 1][b] = true;
        }
        if(arr[a][b - 1] == '.' && !visited[a][b - 1] && b - 1 >= 0) {
            q.push({a, b - 1});
            dist[a][b-1] = dist[a][b] + 1;
            visited[a][b - 1] = true;
        }
    }
    cout << dist[r-1][c-1] << endl;
    
    return 0;
}