#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    unordered_map<int, int> um;

    int sum = 0, mx = -2e9;
    for(int i=0;i<n;++i){
        int x; cin >> x;
        if(um.find(x) != um.end()){
            mx = max(mx, sum+x-um[x]);
        }else{
            um[x] = sum;
        }
        um[x] = min(um[x], sum);
        sum += x;
        mx = max(mx, x);
    }

    cout << mx;
    
}

