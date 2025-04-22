#include <bits/stdc++.h>

using namespace std;
void recur(int i, int k, int &sum){
    if(k == 0) {
        sum++;
        return;
    }
    for (int a = i; a <= k; a++) recur(a, k-a, sum);
}
int main(){
    int n;
    cin >> n;
    int ans = 0;
    recur(1, n, ans);
    cout << ans << '\n';

    return 0;
}