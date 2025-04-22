#include<bits/stdc++.h>
using namespace std;

int dist[510][510];
// copy of hof
vector<int > targets;
bool mark[510];

vector<int > current;

int k;
int minDist = 1e9;

void permute(int state) {
  if(state == k) {
    int currentDist = 0;

    for(int i=1;i<k;i++)
      currentDist += dist[current[i-1]][current[i]];

    minDist = min(minDist, currentDist);

    return ;
  }
  
  for(int i=0;i<k;i++){
    if(mark[i]) continue;

    mark[i] = true;
    current.push_back(targets[i]);

    permute(state+1);

    current.pop_back();
    mark[i] = false;
  }
}

int main() {
  int n,m;
  cin >> n >> m >> k;
  
  targets.resize(k);
  
  for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      dist[i][j] = dist[j][i] = 1e9;
  
  for(auto &x:targets)
    cin >> x;
  
  while(m--){
    int x, y, w;
    cin >> x >> y >> w;
    dist[x][y] = dist[y][x] = min(dist[x][y], w);
  }
  
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  // find any shortest path
  permute(0);
  
  cout << minDist << '\n';
  
  return 0;
}
/*
3 3 3
1 2 3
2 3 7
1 2 15
1 3 4

11
*/