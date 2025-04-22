#include <bits/stdc++.h>

using namespace std;
int n, c[10001], total[10001];
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    total[1] = c[1];
    total[2] = max(c[1], c[2]);

    for (int i = 3; i <= n; ++i) total[i] = max(total[i - 2] + c[i], total[i - 1]);
    
    cout << total[n] << endl;
    return 0;
}