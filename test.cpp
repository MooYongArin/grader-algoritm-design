#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int cc_num = 0;
void dfs1(int idx, vector<vector<int>> &adj, vector<int> &visited){
    visited[idx] = 0;
    for (auto &b : adj[idx])
    {
        if(visited[b] != -1) continue;
        // visited[b] = true;
        dfs1(b, adj, visited);
    }
    
    s.push(idx);
}
void dfs2(int idx, vector<vector<int>> &adj, vector<int> &visited){
    visited[idx] = cc_num;
    for (auto &b : adj[idx])
    {
        if(visited[b] != -1) continue;
        dfs2(b, adj, visited);
    }
}
int main() {
    

    return 0;
}