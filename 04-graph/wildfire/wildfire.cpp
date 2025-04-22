#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m, k, beauty = 0;
    cin >> n >> m >> k;
    int b[n], fire[k];
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        beauty += b[i];
    }
    for (int i = 0; i < k; i++) cin >> fire[i];
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    vector<bool> visited(n, false);
    for (int i = 0; i < k; i++)
    {
        int a = fire[i];
        if (visited[a]) {
            cout << beauty << " ";
            continue;
        }
        queue<int> q;
        q.push(a);
        visited[a] = true;
        beauty -= b[a];
        b[a] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int &v : adj[u])
            {
                if (visited[v]) continue;
                q.push(v);
                visited[v] = true;
                beauty -= b[v];
                b[v] = 0;
            }
        }
        cout << beauty << " ";
    }
    
    return 0;
}