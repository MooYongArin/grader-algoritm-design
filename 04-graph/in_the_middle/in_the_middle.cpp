#include <bits/stdc++.h>
// copy of hof
using namespace std;
void find_dist(int s, vector<int> &dist, vector<vector<int>> &adj) {
    dist[s] = 0;
    queue<int> q;
  
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
  
      for (auto v : adj[u]) {
        if (dist[v] > dist[u] + 1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
}
int main(){
    int n, t1, t2, t3;
    cin >> n >> t1 >> t2 >> t3;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }
    vector<int> dist_x(n + 1, INT_MAX), dist_y(n + 1, INT_MAX), dist_z(n + 1, INT_MAX);
    find_dist(t1, dist_x, adj);
    find_dist(t2, dist_y, adj);
    find_dist(t3, dist_z, adj);

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) ans = min(ans, max(dist_x[i], max(dist_y[i], dist_z[i])));
    
    cout << ans << endl;
    return 0;
}