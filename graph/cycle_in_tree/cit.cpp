#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj(100001);
vector<bool> visited(100001, false);
int dfs(int idx, int &cycle_num, int parent){
    visited[idx] = true;
    for (auto &b : adj[idx])
    {
        if(b == parent) continue;
        cycle_num++;
        if(visited[b]) return cycle_num;
        int result = dfs(b, cycle_num, idx);
        if(result != -1) return result;
        cycle_num--;
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cycle_num = 0;
    cout << dfs(0, cycle_num, -1) << endl;
    return 0;
}