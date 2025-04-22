#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> gd(n); // end, start
    for (int i = 0; i < n; i++) cin >> gd[i].second;
    for (int i = 0; i < n; i++) cin >> gd[i].first;
    
    sort(gd.begin(), gd.end());
    int sum = 1, border = gd[0].first;
    for (int i = 1; i < n; i++)
    {
        if(gd[i].second >= border) {
            border = gd[i].first;
            sum++;
        }
    }
    cout << sum << endl;
    
    return 0;
}