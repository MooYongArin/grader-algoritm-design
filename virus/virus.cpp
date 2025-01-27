#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> v, int k){
    if(k==1) return (v[0] == 0) && (v[1] == 1);

    int mid = v.size() / 2;
    vector<int> vl(mid);
    for (size_t i = 0; i < mid; i++) vl[i] = v[i];
    
    vector<int> vl_rev(vl);
    reverse(vl_rev.begin(), vl_rev.end());

    vector<int> vr(mid);
    for (size_t i = 0; i < mid; i++) vr[i] = v[i + mid];

    bool check_front = check(vl, k-1);
    bool check_front_rev = check(vl_rev, k-1);
    bool check_back = check(vr, k-1);
    return (check_front || check_front_rev) && check_back;
}
int main(){
    int n, k;
    cin >> n >> k;
    int m = 1 << k; // pow(2,k)
    vector<int> v(m);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++) cin >> v[j];
        
        if (check(v, k)) cout << "yes" << endl;
        else cout << "no" << endl;
        
    }

    
    return 0;
}