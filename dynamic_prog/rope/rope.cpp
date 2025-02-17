#include <bits/stdc++.h>

using namespace std;
int n, a, b, c;
vector<int> path(4001, -1);

int main(){
    cin >> n >> a >> b >> c;
    
    path[0] = 0;
    
    for (int i = 1; i <= n; ++i) {
        if(i - a >= 0 && path[i - a] != -1) path[i] = max(path[i], path[i - a] + 1);
        if(i - b >= 0 && path[i - b] != -1) path[i] = max(path[i], path[i - b] + 1);
        if(i - c >= 0 && path[i - c] != -1) path[i] = max(path[i], path[i - c] + 1);
    }

    cout << path[n] << endl;
    

    return 0;
}