#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int Triforce(vector<vector<int>> &v, int rs,int re,int cs,int ce){
    if(re-rs==1) return  v[rs][cs];

    int rm=(rs+re)/2;
    int cm=(cs+ce)/2;

    // check bot right
    for(int i=rm;i<re;i++) for(int j=cm;j<ce;j++) if(v[i][j] != 0) return 0;

    int P=Triforce(v,rs,rm,cs,cm);
    int Q=Triforce(v,rm,re,cs,cm);
    int R=Triforce(v,rs,rm,cm,ce);

    if(!P || !Q || !R) return 0;
    if(P == Q||P == R) return P;
    if(Q == R) return R;
    return 0;
}
int main(){
    for (size_t j = 0; j < 3; j++)
    {
        cin >> n;
        vector<vector<int>> v_all(n, vector<int>(n));
        for (size_t i = 0; i < n; i++) for (size_t k = 0; k < n; k++) cin >> v_all[i][k];

        cout << Triforce(v_all, 0, n, 0, n) << endl;
    }
    
    return 0;
}