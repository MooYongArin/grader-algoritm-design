#include <bits/stdc++.h>
#define tt tuple<int,int,int> // cost,row,col
using namespace std;
int r,c,a1,a2,b1,b2,m[303][303],used[303][303];
int dr[6]={0,0,-1,-1,1,1};
int dce[6]={-1,1,-1,0,-1,0};
int dco[6]={-1,1,0,1,0,1};

int main() {
    cin>>r>>c>>a1>>b1>>a2>>b2;
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            cin>>m[i][j];
        }
    }
    priority_queue<tt,vector<tt>,greater<tt>> q;
    q.emplace(m[a1][b1],a1,b1);
    while (!q.empty()) {
        auto [z,row,col]=q.top();
        q.pop();
        if (used[row][col]) continue;
        used[row][col]=z;
        for (int i=0;i<6;i++) {
            int nrow=row+dr[i];
            int ncol=(row%2)?col+dco[i]:col+dce[i];
            if (1<=nrow&&nrow<=r&&1<=ncol&&ncol<=c&&!used[nrow][ncol]) {
                q.emplace(z+m[nrow][ncol],nrow,ncol);
            }
        }
    }
    cout<<used[a2][b2]<<"\n";
}
