#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int n, q;
int main(){
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);
    cin >> n >> q;
    map<int, int> mp_q, mp_main;
    int amount = 0;
    for (size_t i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        mp_q[a] += b;
    }
    for (auto &i : mp_q) {
        int num = i.first;
        int quan = i.second;
        amount += quan;
        mp_main[amount] = num;
    }
    for (size_t i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        auto it = mp_main.lower_bound(k);
        cout << it->second << endl;
    }
    
    return 0;
}