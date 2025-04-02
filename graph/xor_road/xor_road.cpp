#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> dist(n, INT_MIN);
    vector<int> visited(n, false);
    unsigned long long cost = 0;

    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if(!visited[j] && (u == -1 || dist[u] < dist[j])) 
                u = j;
        }
        visited[u] = true;
        cost += dist[u];
        
        for (int j = 0; j < n; j++)
        {
            dist[j] = max(dist[j], arr[u] ^ arr[j]);
        }
    }
    cout << cost << endl;
    return 0;
}