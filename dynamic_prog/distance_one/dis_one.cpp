#include <bits/stdc++.h>

using namespace std;
const int MAGIC_NUM = 100000007;
int k;
long long cnt[5000];

int main(){
    int n;
    cin >> n >> k;
    for (size_t i = k; i < n; i++)
    {
        cnt[i] = cnt[i - 1] + cnt[i - k];
    }
    
    cout << cnt[n] % MAGIC_NUM << endl;
    return 0;
}