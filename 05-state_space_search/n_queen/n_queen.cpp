#include <bits/stdc++.h>

using namespace std;
int n, cnt = 0;
vector<bool> used(12, false);
vector<int> col(12);

bool isValid(int idx){
    for(int i=0;i<idx;i++){
        if(abs(i-idx) == abs(col[i]-col[idx])) return false;
    }
    return true;
}
void n_queen(int idx){
    if(idx == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(!used[i]) {
            used[i] = true;
            col[idx] = i;
            if(isValid(idx)) n_queen(idx + 1);
            used[i] = false; 
        }
    }
    
}
int main(){
    cin >> n;
    n_queen(0);
    cout << cnt << '\n';
    return 0;
}