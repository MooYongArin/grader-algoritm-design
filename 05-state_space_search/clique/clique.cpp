#include <bits/stdc++.h>

using namespace std;
int n, left_pow = 0;
int f[50][50], b[58], max_pow = INT_MIN;
vector<int> v;
bool isClose(){
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if(f[v[i]][v[j]] != 1 || f[v[j]][v[i]] != 1) return false;
        }
    }
    return true;
}
void recur(int idx, int power, int left_pow){
    if(idx == n) {
        max_pow = max(max_pow, power);
        return;
    }
    if(power + left_pow < max_pow) return;
    
    v.push_back(idx);
    if(isClose()) recur(idx + 1, power + b[idx], left_pow - b[idx]);

    v.pop_back();
    recur(idx + 1, power, left_pow - b[idx]);
}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {cin >> b[i]; left_pow += b[i];}

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {cin >> f[i][j];}

    recur(0, 0, left_pow);
    cout << max_pow << '\n';
    return 0;
}