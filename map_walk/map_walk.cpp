#include <iostream>
#include <vector>

using namespace std;
void walk(vector<vector<int>> &v, int rstart, int cstart, int rend, int cend, string str){
    
    if(rstart == rend && cstart == cend) cout << str << endl;

    v[rstart][cstart] = 1;

    if (cstart < cend && v[rstart][cstart + 1] == 0) walk(v, rstart, cstart + 1, rend, cend, str + "A");
    if (rstart < rend && v[rstart + 1][cstart] == 0) walk(v, rstart + 1, cstart, rend, cend, str + "B");
    if (rstart > 0 && v[rstart - 1][cstart] == 0 ) walk(v, rstart - 1, cstart, rend, cend, str + "C");

    v[rstart][cstart] = 0;
}
int main(){
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(r+1);
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    v[0][0] = 1;
    walk(v, 0, 0, r-1, c-1, "");
    cout << "DONE" << endl;
    
    return 0;
}