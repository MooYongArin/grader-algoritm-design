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
        for (pair<int, int> &i : vector<pair<int, int>> {{1, 0}, {0, 1}, {-1, 0}, {0, -1}})
        {
            int dx = i.first, dy = i.second;
            int x = a + dx, y = b + dy;
            if(x < 0 || y < 0 || x >= r || y >= c || arr[x][y] != '.' || visited[x][y]) continue;
            q.push({x, y});
            dist[x][y] = dist[a][b] + 1;
            visited[x][y] = true;
        }
    }
    cout << dist[r-1][c-1] << endl;
    
    return 0;
}
