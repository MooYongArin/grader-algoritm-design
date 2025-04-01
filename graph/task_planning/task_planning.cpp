#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int pa;
            cin >> pa;
            adj[pa].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) if (indegree[i] == 0) {
        q.push(i);
    }
    while (!q.empty())
     {
        int a = q.front();
        q.pop();
        cout << a << " ";
        for (int &b : adj[a])
        {
            indegree[b]--;
            if (indegree[b] == 0) q.push(b);
        }
     }
    
    return 0;
}