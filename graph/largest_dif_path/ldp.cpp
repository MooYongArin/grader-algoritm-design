#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int c[n];
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }

     queue<int> q;
     vector<int> max_diff(n, 0);
     for (int i = 0; i < n; i++) if (indegree[i] == 0) {
        q.push(i);
        max_diff[i] = 0;
    }

     int max_path = 0;
     while (!q.empty())
     {
        int a = q.front();
        q.pop();
        for (int &b : adj[a])
        {
            indegree[b]--;
            if (indegree[b] == 0) q.push(b);
            max_diff[b] = max(max_diff[b], max_diff[a] + c[b] - c[a]);
            max_path = max(max_path, max_diff[b]);
        }
     }
    
    cout << max_path << endl;
    return 0;
}