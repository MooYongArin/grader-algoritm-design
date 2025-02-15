#include <iostream>
#include <vector>

using namespace std;
int a, b;
void recur(vector<vector<int>> &v, int a, int b,int row,int col){
    if(a == 0) {
        v[row][col] = b;
        return;
    }
    recur(v,a-1,b,row,col);
    recur(v,a-1,b-1,row,col + (1 << (a-1)));
    recur(v,a-1,b+1,row + (1 << (a-1)),col);
    recur(v,a-1,b,row + (1 << (a-1)),col + (1 << (a-1)));
}
int main(){
    cin >> a >> b;
    vector<vector<int>> v(1 << a, vector<int>(1 << a));
    recur(v, a, b, 0, 0);
    for (auto &sub_vec : v)
    {
        for (auto &i : sub_vec) cout << i << " ";
        cout << endl;
    }
    
    return 0;
}