#include <bits/stdc++.h>

using namespace std;
const int MOD = 32717;
int recur_mem[1000][1000], c[1001], a[1000], k;
long long recur(int n){
    if(n < k) return a[n] % MOD;
    if(recur_mem[n][k] != 0) return recur_mem[n][k];

    int lr = 0;
    for (size_t i = 1; i <= k; ++i) 
        lr = ((lr % MOD) + ((c[i] % MOD * recur(n - i) % MOD) % MOD) % MOD) % MOD;

    recur_mem[n][k] = lr;
    return lr;
    
}
int main(){
    int n;
    cin >> k >> n;
    for (int i = 1; i <= k; ++i) cin >> c[i];
    for (int i = 0; i < k; ++i) cin >> a[i];
    cout << recur(n) << endl;

    return 0;
}