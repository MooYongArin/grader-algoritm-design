#include <iostream>
#include <vector>

using namespace std;
int n, k;
void solve(vector<int>& v, int l, int r, int& k) {
    if(k <= 0 || l == r-1) return;
    
    int m = (l+r) / 2;
    if(k > 0) { 
        swap(v[m-1],v[m]); 
        k--; 
    }
    solve(v, l, m, k);
    solve(v, m, r, k);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    if(k > (2 * n) - 1 || k%2 == 0) {
        cout << -1;
        return 0;
    }
    vector<int> num(n);
    for(int i=0; i<n; i++) num[i] = i+1;
    int cnt = (k-1)/2;
    solve(num,0,n,cnt);
    for(auto &x : num) cout << x << " ";
    return 0;
}