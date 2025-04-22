#include <bits/stdc++.h>

using namespace std;
int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);
    vector<bool> visited(v, false);
    vector<int> indegree(v, 0);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
        indegree[a]++;
        indegree[b]++;
    }

    int line = 0;
    for (int i = 0; i < v; i++)
    {
        // 1 connected component
        bool is_line_component = true;
        queue<int> q;
        if(visited[i]) continue;
        q.push(i);
        visited[i] = true;
        
        int node_count = 0; 
        int edge_count = 0; 
        while (!q.empty())
        {
            int a = q.front();
            q.pop();
            if (indegree[a] > 2) is_line_component = false; 
            node_count++; 
            edge_count += adj[a].size(); 
            for (int &b : adj[a])
            {
                if(visited[b]) continue;
                visited[b] = true;
                q.push(b);
            }
        }
        edge_count /= 2;
        if(is_line_component && edge_count == node_count - 1) line++;
    }
    
    cout << line << endl;
    return 0;
}