#include <bits/stdc++.h>

using namespace std;

struct State {
    int space; 
    int last_space;
    vector<int> cur_state;
    vector<int> combi;
};

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
    
    stack<State> q;
    q.push({2 * n, -1, start, {}});
    same.insert(start);

    while (!q.empty()) {
        State current = q.top();
        q.pop();

        int space = current.space;
        vector<int> cur_state = current.cur_state;
        vector<int> combi = current.combi;

        for (int b : adj[space]) {
            swap(cur_state[b], cur_state[space]);

            if (same.find(cur_state) == same.end() && current.last_space != b) { // NOT FOUND
                combi.push_back(b + 1);
                if (cur_state == ans) {
                    cout << combi.size() << '\n';
                    for (auto &i : combi) {
                        cout << i << " ";
                    }
                    return 0;
                }
                q.push({b, space, cur_state, combi});
                same.insert(cur_state);
                combi.pop_back();
            }

            swap(cur_state[b], cur_state[space]);
        }
    }

    cout << -1 << '\n';
    return 0;
}
