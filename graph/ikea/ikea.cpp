#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n + 1); // Adjusted for 1-based indexing
    vector<int> indegree(n + 1, 0);

    // Read the graph
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    // Process 5 sequences
    for (int i = 0; i < 5; i++) {
        vector<int> s(n);
        for (int j = 0; j < n; j++) cin >> s[j];

        vector<int> temp_indegree = indegree;
        bool isSuccess = true;

        for (int idx = 0; idx < n; idx++) {
            int current = s[idx];

            // Check if the current node has an indegree of 0
            if (temp_indegree[current] != 0) {
                isSuccess = false;
                break;
            }

            // Reduce the indegree of all neighbors
            for (auto &b : adj[current]) {
                temp_indegree[b]--;
            }
        }

        if (isSuccess) cout << "SUCCESS" << endl;
        else cout << "FAIL" << endl;
    }

    return 0;
}