#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    vector<vector<int>> arr(r, vector<int>(c));
    vector<pair<int, int>> starts;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                starts.push_back({i, j});
            }
        }
    }
    vector<vector<int>> min_dist(r, vector<int>(c, INT_MAX));
    vector<vector<int>> max_dist(r, vector<int>(c, INT_MIN));
    queue<pair<int, int>> q;
    

    for (int k = 0; k < starts.size(); k++) {
        q.push(starts[k]);
        vector<vector<int>> dist(r, vector<int>(c, -1));
        dist[starts[k].first][starts[k].second] = 0;

        while (!q.empty()) {
            auto pos = q.front();
            int x = pos.first, y = pos.second;
            q.pop();

            for (auto p : vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
                int dx = p.first, dy = p.second;
                int nx = x + dx, ny = y + dy;
                if(nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] == 1 || dist[nx][ny] != -1) continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
                    
                min_dist[nx][ny] = min(min_dist[nx][ny], dist[nx][ny]);
                max_dist[nx][ny] = max(max_dist[nx][ny], dist[nx][ny]);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != 0) continue;
            if (min_dist[i][j] == INT_MAX || max_dist[i][j] == INT_MIN) continue;
            if (abs(max_dist[i][j] - min_dist[i][j]) <= 1) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) cout << min_dist[i][j] << " ";
    //     cout << '\n';
    // }
    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) cout << max_dist[i][j] << " ";
    //     cout << '\n';
    // }
    return 0;
}
