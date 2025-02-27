#include <bits/stdc++.h>

using namespace std;
int n, m, a[100001], x[100001];
bool isSorted(vector<int> &v){
    for (int i = 1; i < v.size(); i++)
    {
        if(v[i - 1] > v[i]) return false;
    }
    return true;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        bool isStable = true;
        vector<int> b;
        for (int j = 1; j <= n; j++) {
            cin >> x[j];
            auto it = find(b.begin(), b.end(), a[x[j]]);
            if(it != b.end() && x[j] < x[it - b.begin() + 1]) isStable = false;
            b.push_back(a[x[j]]);
        }
        if(isSorted(b)) cout << "1 ";
        else cout << "0 ";
        if(isSorted(b) && isStable) cout << "1";
        else cout << "0";
        cout << endl;
    }
    
    return 0;
}