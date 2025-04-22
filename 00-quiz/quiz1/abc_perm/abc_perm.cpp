#include <iostream>
#include <vector>

using namespace std;
vector<string> forbid, ans;
int n;
bool isValid(string &str){
    for (size_t i = 0; i < str.length() - 1; i++)
    {
        for (string &contrain : forbid) if(str[i] == contrain[0] && str[i+1] == contrain[1]) return false;
    }
    return true;
}
void perm(int len,int a, int b, int c, string st) {
    if(len == n && isValid(st)) ans.push_back(st);
    if(len > n) return;
    if(a != 0) perm(len + 1, a-1, b, c, st + "A");
    if(b != 0) perm(len + 1, a, b-1, c, st + "B");
    if(c != 0) perm(len + 1, a, b, c-1, st + "C");
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    int i, j, k, m;
    cin >> n >> i >> j >> k >> m;
    forbid.resize(m);
    for (size_t i = 0; i < m; i++) cin >> forbid[i];

    perm(0, i, j, k, "");
    cout << ans.size() << endl;
    for (auto &i : ans) cout << i << endl;
    
    return 0;
}