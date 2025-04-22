#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    int weight[n][n];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            cin >> weight[i][j];
            weight[j][i] = weight[i][j];
        }
    }

    vector<int> dist(n, INT_MAX);
    vector<int> visited(n, false);
    int min_cost = 0;
    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        min_cost += dist[u];
        visited[u] = true;

        for(int j=0;j<n;j++)
            dist[j] = min(dist[j], weight[u][j]);
    }
    
    cout << min_cost << endl;
    return 0;
}