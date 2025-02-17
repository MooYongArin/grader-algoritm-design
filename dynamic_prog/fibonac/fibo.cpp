#include <bits/stdc++.h>

using namespace std;
int fibo_mem[45];
long long fibo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(fibo_mem[n] != 0) return fibo_mem[n];
    int k = fibo(n-1) + fibo(n-2);
    fibo_mem[n] = k;
    return k;
}
int main(){
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}