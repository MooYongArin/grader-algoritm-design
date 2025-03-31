#include <bits/stdc++.h>

using namespace std;
bool dfs(int idx, vector<vector<int>> &adj, vector<bool> &visited, int parent){
    visited[idx] = true;
    for (int &b : adj[idx])
    {
        if(b == parent) continue;
        if(visited[b]) return true;
        if (dfs(b, adj, visited, idx)) return true;
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> adj(n);

        for (int i = 0; i < e; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> visited(n, false);
        bool hasCycle = false;
        for (int i = 0; i < n; i++)
        {
            if(!visited[i]) 
                if(dfs(i, adj, visited, -1)) 
                    { hasCycle = true; break;}
        }
        cout << (hasCycle ? "YES" : "NO") << endl;
    }
    return 0;
}