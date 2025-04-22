#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, e, k, ans = 0;
    cin >> n >> e >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> q;
    vector<int> dist(n + 1, -1);
    q.push(0);
    dist[0] = 0;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (int &b : adj[a])
        {
            if(dist[b] != -1) continue;
            q.push(b);
            dist[b] = dist[a] + 1;
            if(dist[b] == k) ans++;
        }
        
    }
    cout << ans << endl;

    return 0;
}