#include <bits/stdc++.h>

using namespace std;
// copy of hof
int main(){
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    pair<int, int> gd[m];
    int p[m], h[m], health = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
        gd[i].first = p[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> h[i];
        gd[i].second = h[i];
        health += h[i];
    }
    sort(gd, gd + m);

    int idx = 0;
    for(int i=1;i<=n;i++){
        while(gd[idx].first < i-w) idx++;
        if(gd[idx].first > i+w) continue;

        gd[idx].second--;
        k--;

        if(k == 0) break;
        if(gd[idx].second == 0) idx++;
    }

    int ans = 0;
    for(int i=0;i<m;i++){
        ans += gd[i].second;
    }
    cout << ans;
    return 0;
}