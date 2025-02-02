#include <bits/stdc++.h>
using namespace std;

// | v[0] v[1] |
// | v[2] v[3] |
vector<int> multiplly(vector<int> v, vector<int> w, int k){
    vector<int> res(4);
    res[0] = (v[0]*w[0] + v[1]*w[2]) % k;
    res[1] = (v[0]*w[1] + v[1]*w[3]) % k;
    res[2] = (v[2]*w[0] + v[3]*w[2]) % k;
    res[3] = (v[2]*w[1] + v[3]*w[3]) % k;
    return res;
}
vector<int> calculate(vector<int> &v, int n, int k){
    if(n == 1) return {v[0]%k, v[1]%k, v[2]%k, v[3]%k};
    vector<int> p  = calculate(v,n/2,k); // v ^ n/2
    p = multiplly(p,p,k); //p*p % k
    if(n%2 == 0) {
        return p;
    } else {
        return multiplly(v,p,k); // 
    }
}
int main(){
    int n, k;
    vector<int> v(4);
    cin >> n >> k;
    cin >> v[0] >> v[1] >> v[2] >> v[3];
    vector<int> res(4);
    res = calculate(v, n, k);
    cout  <<  res[0] << " " << res[1] << " " << res[2] << " " << res[3];
}