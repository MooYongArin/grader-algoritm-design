#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<vector<int>> v(2, vector<int>(2));

int process(int step, long long r, long long c, bool neg){
    if(n - step == 1) {
        if(neg) return -v[r][c];
        return v[r][c];
    }
    long long size = 1LL << (n -step);
    if(r < size / 2 && c < size / 2) return process(step + 1, r, c, neg);
    if(r < size / 2 && c >= size / 2) return process(step + 1, c - size / 2, r, neg);
    if(r >= size / 2 && c < size / 2) return process(step + 1, r - size / 2, c, !neg);
    return process(step + 1, c - size / 2, r - size / 2, !neg);

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> v[0][0] >> v[0][1] >> v[1][0] >> v[1][1];
    for (size_t i = 0; i < m; i++)
    {
        long long r, c;
        cin >> r >> c;
        --r;
        --c;
        cout << process(0, r, c, false) << endl;
    }
    
    return 0;
}