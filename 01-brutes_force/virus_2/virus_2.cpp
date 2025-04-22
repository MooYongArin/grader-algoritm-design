#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_virus(vector<int> v, int k){
    if(k==1) return true;
    int m = v.size() / 2, front_ones = 0, back_ones = 0;
    vector<int> v_front(m);
    for (size_t i = 0; i < m; i++) {
        if(v[i] == 1) front_ones++;
        v_front[i] = v[i];
    }
    
    vector<int> v_back(m);
    for (size_t i = 0; i < m; i++) {
        if(v[i + m] == 1) back_ones++;
        v_back[i] = v[i + m];
    }
    bool check_diff = (abs(front_ones - back_ones) <= 1);
    return check_diff && check_virus(v_front, k-1) && check_virus(v_back, k-1);
}
int main(){
    int n, k;
    cin >> n >> k;
    int m = 1 << k;
    vector<int> v(m);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++) cin >> v[j];
        if(check_virus(v, k)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    
    return 0;
}