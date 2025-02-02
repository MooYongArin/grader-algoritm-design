#include <iostream>
#include <vector>

using namespace std;
int n, m, target;
vector<int> v;
int bs_near(int i, int j){
    while (i < j)
    {
        int m = (i + j + 1) / 2;
        if (v[m] <= target) i = m;
		else j = m - 1;
    }
    return j;
}
int main(){
    cin >> n >> m;
    v.resize(n);
    for (size_t i = 0; i < n; i++) cin >> v[i];
    for (size_t i = 0; i < m; i++) {
        cin >> target;
        if(target < v[0]) cout << -1 << endl;
        else cout << bs_near(0,n-1) << endl;
    }
    return 0;
}