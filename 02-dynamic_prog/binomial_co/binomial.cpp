#include <bits/stdc++.h>

using namespace std;
int bino_mem[30][30];

long long bino(int n, int k){
    if(n == k || k == 0) return 1;
    if(bino_mem[n][k] != 0) return bino_mem[n][k];
    int cnk = bino(n-1, k-1) + bino(n-1, k); 
    bino_mem[n][k] = cnk;
    return cnk;
}
int main(){
    int n, k;
    cin >> n >> k;
    cout << bino(n, k) << endl;
    return 0;
}