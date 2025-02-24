#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, arr[1001], dp[1001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int maxN = 1;
    for (int i = 1; i <= n; i++) dp[i] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxN = max(maxN, dp[i]);
    }

    cout << maxN << endl;

    return 0;
}