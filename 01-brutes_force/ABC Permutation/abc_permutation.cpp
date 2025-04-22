#include <iostream>
#include <vector>

using namespace std;

void abc_perm(int n, int a, int b, int c, string &st, vector<string> &v){
    if(st.length() == n) v.push_back(st);
    if(a != 0) {
        abc_perm(n, a-1, b, c, st += "A", v);
        st.pop_back();
    }
    if(b != 0) {
        abc_perm(n, a, b-1, c, st += "B", v);
        st.pop_back();
    }
    if(c != 0) {
        abc_perm(n, a, b, c-1, st += "C", v);
        st.pop_back();
    }
}
int main(){
    int n, i, j, k;
    vector<string> v;
    string str = "";
    cin >> n >> i >> j >> k;
    abc_perm(n,i,j,k, str, v);
    cout << v.size() << "\n";
    for (auto &i : v) cout << i << "\n";
    
    return 0;
}
