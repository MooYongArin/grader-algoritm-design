#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &x) {
    cout << "[";
    for (size_t i = 0; i < x.size(); ++i) {
        cout << x[i];
        if (i < x.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

void generateArrays(int n, int m, vector<int> &current, vector<vector<int>> &dp) {
    if (n == 0) {
        if (m == 0) {
            display(current);
        }
        return;
    }

    for (int i = 1; i <= m; ++i) {
        if (dp[n - 1][m - i] > 0) {
            current.push_back(i);
            generateArrays(n - 1, m - i, current, dp);
            current.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 1; k <= j; ++k) {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }

    vector<int> current;
    generateArrays(n, m, current, dp);

    return 0;
}