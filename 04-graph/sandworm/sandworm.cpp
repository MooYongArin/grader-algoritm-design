#include <bits/stdc++.h>

using namespace std;
int main(){
    int r, c, k;
    cin >> r >> c >> k;
    int n[r][c], s[r][c], portal[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> n[i][j];
            portal[i][j] = 0;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        portal[a][b] = 1;
    }
    queue<pair<int, int>> q;
    vector<pair<int, int>> warp;
    q.push({0, 0});
    int cnt = 0;
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int a = p.first, b = p.second;
        if(a + 1 < r && n[a + 1][b] == 0) {
            if(portal[a+1][b] == 1) warp.push_back({a+1, b});
            q.push({a + 1, b});
            n[a + 1][b] = 1;
            cnt++;
        }
        if(b + 1 < c && n[a][b + 1] == 0) {
            if(portal[a][b+1] == 1) warp.push_back({a, b+1});
            q.push({a, b + 1});
            n[a][b + 1] = 1;
            cnt++;
        }
        if(a - 1 >= 0 && n[a - 1][b] == 0) {
            if(portal[a-1][b] == 1) warp.push_back({a-1, b});
            q.push({a - 1, b});
            n[a - 1][b] = 1;
            cnt++;
        }
        if(b - 1 >= 0 && n[a][b - 1] == 0) {
            if(portal[a][b-1] == 1) warp.push_back({a, b-1});
            q.push({a, b - 1});
            n[a][b - 1] = 1;
            cnt++;
        }
    }

    int max_cnt = 0;
    for (auto &i : warp)
    {
        queue<pair<int, int>> q;
        q.push({i.first, i.second});
        int cnt_s = 0;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int a = p.first, b = p.second;
            if(a + 1 < r && s[a + 1][b] == 0) {
                q.push({a + 1, b});
                s[a + 1][b] = 1;
                cnt_s++;
            }
            if(b + 1 < c && s[a][b + 1] == 0) {
                q.push({a, b + 1});
                s[a][b + 1] = 1;
                cnt_s++;
            }
            if(a - 1 >= 0 && s[a - 1][b] == 0) {
                q.push({a - 1, b});
                s[a - 1][b] = 1;
                cnt_s++;
            }
            if(b - 1 >= 0 && s[a][b - 1] == 0) {
                q.push({a, b - 1});
                s[a][b - 1] = 1;
                cnt_s++;
            }
        }
        max_cnt = max(max_cnt, cnt_s);
    }
    
    cout << cnt + max_cnt << endl;
    return 0;
}