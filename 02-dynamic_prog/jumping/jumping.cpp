#include <bits/stdc++.h>

using namespace std;
int a[1000000], n, B[1000000];
int main(){
    cin >> n;
    for (size_t i = 1; i <= n; i++) cin >> a[i];
    B[1] = a[1];
    B[2] = a[1] + a[2];
    B[3] = max(a[1] + a[2] + a[3], a[1] + a[3]);

    for (size_t i = 4; i <= n; i++) B[i] = max(max(B[i - 1], B[i - 2]), B[i - 3]) + a[i];
    
    cout << B[n] << endl;
    return 0;
}