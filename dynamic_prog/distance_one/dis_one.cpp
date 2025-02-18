#include <bits/stdc++.h>

using namespace std;
const int mod = 100000007;
int k;
int v[5001], one[5001];

int bit(int i) {
    if(v[i] != 0) return v[i];
    v[i] = (2 * bit(i - 1)) % mod;
    one[i] = v[i - 1];
    for(int j = 1; j < k && i - j >= 0; j++) {
        v[i] = (v[i] % mod - one[i - j] % mod +   mod) % mod;
        one[i] = (one[i] % mod - one[i - j] % mod +   mod) % mod;
    }
    return v[i];
}

int main(){
    int n;
    cin >> n >> k;
    v[0] = 0;
    v[1] = 2;

    one[0] = 0;
    one[1] = 1;
    cout << bit(n) << "\n";
    return 0;
}