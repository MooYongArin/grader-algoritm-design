#include <bits/stdc++.h>
using namespace std;

vector<int> multiplly(vector<int> v, vector<int> w, int k){
    return v;
}
vector<int> calculate(vector<int> v, int n, int k){
    if(n == 1) return v;
}
int main(){
    int n, k;
    vector<int> v(4);
    cin >> n >> k;
    cin >> v[0] >> v[1] >> v[2] >> v[3];
    vector<int> res = calculate(v, n, k);
    cout << " " <<  res[0] << " " << res[1] << " " << res[2] << " " << res[3];
}