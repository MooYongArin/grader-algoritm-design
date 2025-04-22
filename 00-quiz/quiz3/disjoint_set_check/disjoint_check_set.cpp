#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < q; i++)
    {
        int p[n + 1];
        vector<int> start;
        vector<vector<int>> child(n+1);
        for (int j = 1; j <= n; j++)
        {
            cin >> p[j];
            if(p[j] == -1) start.push_back(j);
            else child[p[j]].push_back(j);
        }

        vector<int> visited(n + 1, 0);
        int max_cnt = 0;
        bool is_union = true;
 
        queue<int> q;
        int cc_num = 1;
        for (auto &v : start)
        {
            int cnt = 1;
            q.push(v);
            visited[v] = cc_num;
            while (!q.empty())
            {
                int a = q.front();
                q.pop();
                for (auto &b : child[a])
                {
                    if(visited[b] != 0) continue;
                    q.push(b);
                    visited[b] = cc_num;
                    cnt++;
                }
            }
            cc_num++;
            max_cnt = max(max_cnt, cnt);
        }

        for (int j = 1; j <= n; j++) if(visited[j] == 0) is_union = false;

        if(is_union)  cout << "1 " << max_cnt << '\n';
        else cout << "0 0" << '\n';

    }
    


    return 0;
}