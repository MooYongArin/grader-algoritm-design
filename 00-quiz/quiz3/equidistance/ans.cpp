#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define sz(x) (int)(x.size())
#define DEBUG(x) cout<<"Debug "<<#x<<" : "<<x<<endl;
#define EL "\n";

// copy of hof
using namespace std;
void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
int n,m;
const int N=1e3+5;
int arr[N][N];
int dist[51][N][N];
bool chk(int x,int y){
    if(x<=0 or y<=0 or x>n or y>m or arr[x][y]==1) return false;
    return true;
}
int row[]={-1,1,0,0};
int col[]={0,0,-1,1};
void solve(){
    cin>>n>>m;
    vector<pii> start;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=50;k++){
                dist[k][i][j]=1e9+7;
            }
            cin>>arr[i][j];
            if(arr[i][j]==2) start.pb({i,j});
        }
    }
    int idx=0;
    for(auto it:start){
        queue<pii> q;
        q.push({it.st,it.nd});
        dist[idx][it.st][it.nd]=0;
        while(!q.empty()){
            pii u=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int dx=u.st+row[i],dy=u.nd+col[i];
                if(!chk(dx,dy)) continue;
                if(dist[idx][u.st][u.nd]+1<dist[idx][dx][dy]){
                    dist[idx][dx][dy]=dist[idx][u.st][u.nd]+1;
                    q.push({dx,dy});
                }
            }
        }
        idx++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]==1) continue;
            int mi=INT_MAX,ma=INT_MIN;
            for(int k=0;k<idx;k++){
                mi=min(mi,dist[k][i][j]);
                ma=max(ma,dist[k][i][j]);
            }
            if(mi==1e9+7 or ma==1e9+7 ) continue;
            if(abs(ma-mi)<=1) cnt++;
        }
    }
    cout<<cnt<<EL;
}
int main(){
    fast();
    solve();
    return 0;
}
/*
5 5
0 0 0 0 0
1 1 0 1 1
2 1 0 1 2
1 1 0 1 1
0 0 0 0 0
*/
