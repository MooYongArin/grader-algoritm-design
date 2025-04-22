#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    double ans = 0;
    int sum[m], a[m];
    for (int i = 0; i < m; i++) cin >> a[i];
    sort(a, a + m);
    sum[0] = a[0];
    for (int i = 1; i < n; i++) sum[i] = a[i];

    for (int i = n; i < m; i++) sum[i] = sum[i - n] + a[i];
    for (int &i : sum) ans += i;
    
    cout << fixed << setprecision(3) << ans/m << endl;
    
    return 0;
}