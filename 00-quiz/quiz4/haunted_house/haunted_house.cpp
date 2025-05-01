#include <bits/stdc++.h>

using namespace std;

struct State {
    int heuristic;
    int last_space;
    int space; 
    vector<int> cur_state;
    vector<int> combi;

    bool operator<(const State& other) const {
        return heuristic > other.heuristic; // Min-heap based on heuristic value
    }
};

int heuristic(const vector<int>& state, const vector<int>&target) {
    int dist = 0;
    for (int i = 0; i < state.size(); i++) {
        if (state[i] != target[i]) {
            dist++;
        }
    }
    return dist;
}
int main() {
    int n, m;
    cin >> n >> m; // 0 -> red, 1 -> blue, 2 -> space
    vector<vector<int>> adj(2 * n + 1);
    set<vector<int>> same;
    vector<int> ans, start;

    for (int i = 0; i < n; i++) ans.push_back(1);
    for (int i = n; i < 2 * n; i++) ans.push_back(0);
    ans.push_back(2);

    for (int i = 0; i < n; i++) start.push_back(0);
    for (int i = n; i < 2 * n; i++) start.push_back(1);
    start.push_back(2);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    priority_queue<State> q;
    q.push({heuristic(start, ans), -1, 2 * n, start, {}});
    same.insert(start);

    while (!q.empty()) {
        State current = q.top();
        q.pop();

        int space = current.space;
        vector<int> cur_state = current.cur_state;
        vector<int> combi = current.combi;

        for (int b : adj[space]) {
            if (current.last_space == b) continue; // Skip if it's a space
            swap(cur_state[b], cur_state[space]);

            if (same.find(cur_state) == same.end()) { // NOT FOUND
                combi.push_back(b + 1);
                if (cur_state == ans) {
                    cout << combi.size() << '\n';
                    for (auto &i : combi) {
                        cout << i << " ";
                    }
                    return 0;
                }
                q.push({heuristic(cur_state, ans), space, b, cur_state, combi});
                same.insert(cur_state);
                combi.pop_back();
            }

            swap(cur_state[b], cur_state[space]);
        }
    }

    cout << -1 << '\n';
    return 0;
}

