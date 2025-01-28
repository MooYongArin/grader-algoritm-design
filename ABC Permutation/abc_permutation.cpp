#include <iostream>
#include <vector>

using namespace std;

void abc_perm(int n, int a, int b, int c, string st, vector<string> &v){
    if(st.length() == n) v.push_back(st);
    if(a != 0) abc_perm(n, a-1, b, c, st + "A", v);
    if(b != 0) abc_perm(n, a, b-1, c, st + "B", v);
    if(c != 0) abc_perm(n, a, b, c-1, st + "C", v);
}
int main(){
    int n, i, j, k;
    vector<string> v;
    cin >> n >> i >> j >> k;
    abc_perm(n,i,j,k, "", v);
    cout << v.size() << endl;
    for (auto &i : v) cout << i << endl;
    
    return 0;
}