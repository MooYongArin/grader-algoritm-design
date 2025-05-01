#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> visited(n, false);
    unsigned long long maxCost = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        int weight = p.first;
        int u = p.second;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        maxCost += weight;

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int edgeWeight = arr[u] ^ arr[v];
                pq.push({edgeWeight, v});
            }
        }
    }
    cout << maxCost << endl;
    return 0;
}
