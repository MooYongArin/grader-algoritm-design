#include <bits/stdc++.h>

using namespace std;
int n, k, m, d[200001], w[100001], p[100001];
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        d[i] += (d[i - 1] - m);
    }
    for (int i = 1; i <= k; i++) {
        cin >> p[i] >> w[i];
        int l = p[i], r = n;
        while (l < r)
        {
            int m = (l + r) / 2;
            if(d[m] - d[p[i] - 1] < w[i]) l = m + 1;
            else r = m;
        }
        cout << r << '\n';
        // auto it = lower_bound(d + p[i], d + n, w[i] + d[p[i] - 1]);
        // cout << it - d << '\n';
    }
    return 0;
}