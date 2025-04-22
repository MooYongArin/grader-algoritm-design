#include <bits/stdc++.h>

using namespace std;
vector<bool> sel(101, false);
int n;
double W, v[101], w[101], tail[101];
double maxN = -1e9;
void recur(int idx, double sumW, double sumP, double bound){
    if(sumW > W) return;
    if (bound < maxN) return;
    if (tail[idx] + sumP < maxN) return;
    if (idx < n)
    {
        sel[idx] = 1;
        recur(idx + 1, sumW + w[idx], sumP + v[idx], bound);

        sel[idx] = 0;
        bound -= v[idx];
        recur(idx + 1, sumW, sumP, bound);
    } else {
        if(sumW <= W) maxN = max(sumP, maxN);
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> W >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> w[i];

    tail [n - 1] = v[n - 1];
    for (int i = n - 2;i >= 0; i--) tail[i] = tail[i + 1] + v[i];
    recur(0, 0, 0, tail[0]);
    cout << fixed << setprecision(4) << maxN << '\n';
    return 0;
}
/*
10.0 4
1.2 3.4 6.3 1.3
4.2 1.4 6.7 4.3
9.7
*/