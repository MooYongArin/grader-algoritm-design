#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, e, k;
    cin >> n >> e >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int max_cnt = -1;
    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(n, false);
        vector<int> cnt(n, 0), deg(n, 0);
        int count = 0;
        queue<int> q;
        if(visited[i]) continue;
        q.push(i);
        deg[0]++;
        visited[i] = true;
        while (!q.empty())
        {
            int a = q.front();
            q.pop();
            for (int &b : adj[a])
            {
                if(visited[b]) continue;
                q.push(b);
                cnt[b] = cnt[a] + 1;
                deg[cnt[b]]++;
                visited[b] = true;
            }
        }
        int sum = 0;
        for(int j=0;j<=k;j++)
            sum += deg[j];

        max_cnt = max(max_cnt, sum);
    }
    
    cout << max_cnt << endl;
    return 0;
}