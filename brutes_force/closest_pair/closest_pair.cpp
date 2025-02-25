#include <bits/stdc++.h>

using namespace std;
int n, minN = 1e9;
pair<int, int> p[50001];
int squared_distance(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(p, p + n);

    for(int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++)
        {
            if(p[j].first >= p[i].first + minN) break;
            int d = squared_distance(p[i], p[j]);
            minN = min(minN, d);
            j++;
        }
    }
    cout << minN << endl;
    return 0;
}
