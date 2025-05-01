#include <bits/stdc++.h>

using namespace std;
int main(){ 
    int r, c, k;
    cin >> r >> c >> k;
    int arr[r][c];

    vector<pair<int, int>> start;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) start.push_back({i, j});
        }
    }

    vector<vector<int>> min_dist(r, vector<int>(c, INT_MAX));
    vector<vector<int>> max_dist(r, vector<int>(c, INT_MIN));
    vector<int> up = {1, 0, -1, 0};
    vector<int> right = {0, 1, 0, -1};
    for (int i = 0; i < start.size(); i++)
    {
        queue<pair<int, int>> q;
        vector<vector<int>> dist(r, vector<int>(c, -1));
        int a = start[i].first, b = start[i].second;
        q.push({a, b});
        dist[a][b] = 0;
        min_dist[a][b] = min(min_dist[a][b], dist[a][b]);
        max_dist[a][b] = max(max_dist[a][b], dist[a][b]);
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int dx = right[i], dy = up[i];
                int new_x = x + dx, new_y = y + dy;
                if(new_x < 0 || new_y < 0 || new_x >= r || new_y >= c || dist[new_x][new_y] != -1 || arr[new_x][new_y] == 1) continue;
                dist[new_x][new_y] = dist[x][y] + 1;
                q.push({new_x, new_y});
                
                min_dist[new_x][new_y] = min(min_dist[new_x][new_y], dist[new_x][new_y]);
                max_dist[new_x][new_y] = max(max_dist[new_x][new_y], dist[new_x][new_y]);
            }   
            
        }
        
    }

    int cnt = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            {
                if(min_dist[i][j] == INT_MAX || max_dist[i][j] == INT_MIN) continue;
                if(max_dist[i][j] - min_dist[i][j] <= k) cnt++;
            }
    }
    cout << cnt << '\n';
    return 0;
}
/*
2 10 1
0 0 2 0 0 0 0 0 0 0
0 0 0 0 0 0 2 0 0 0

4
*/
