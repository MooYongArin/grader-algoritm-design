#include <bits/stdc++.h>

using namespace std;
int cc_num = 0;
void dfs(vector<vector<int>> &adj, int idx, vector<int> &visited){
    visited[idx] = cc_num;
    for (auto &i : adj[idx])
    {
        if(visited[i] == 0) 
            dfs(adj, i, visited);
    }
    
}
int main(){
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v + 1);
    vector<int> visited(v + 1);
    fill(visited.begin(), visited.end(), 0);
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= v; i++) {
        if(visited[i] == 0) {
            cc_num++;
            dfs(adj, i, visited);
        }
    }
    cout << cc_num << endl;
    return 0;
}