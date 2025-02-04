#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int n, ans;
long long y[MAX_N];

int solve(long long b, long long c) {
    int res = upper_bound(y + 1, y + n + 1, c) - lower_bound(y + 1, y + n + 1, b);
    if (res == 0) return 0;
    if (c - b + 1 < 3) return res;

    long long u = (c - b + 1) / 3;
    long long v = (c - b + 2) / 3;

    int v1 = solve(b, b + u - 1);
    int v2 = solve(b + u, b + u + v - 1);
    int v3 = solve(b + u + v, c);

    return res + v1 + v2 + v3 - min({v1, v2, v3});
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long w;
    cin >> w >> n;

    for (int i = 1; i <= n; i++) {
        cin >> y[i];
    }

    sort(y + 1, y + n + 1);
    
    cout << solve(1ll, w);
    return 0;
}
