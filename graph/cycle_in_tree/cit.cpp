#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(100001);
vector<bool> visited(100001, false);
vector<int> parent(100001, -1);

int find_cycle_length(int start, int end) {
    int length = 1; 
    int current = end;
    while (current != start) {
        length++;
        current = parent[current];
    }
    return length;
}

int dfs(int idx, int &cycle_length) {
    visited[idx] = true;
    for (auto &b : adj[idx]) {
        if (b == parent[idx]) continue;
        if (visited[b]) {
            cycle_length = find_cycle_length(b, idx);
            return cycle_length;
        }
        parent[b] = idx;
        int result = dfs(b, cycle_length);
        if (result != -1) return result;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cycle_length = 0;
    dfs(0, cycle_length);
    cout << cycle_length << endl;
    return 0;
}