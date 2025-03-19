#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    queue<int> store, plant;
    vector<vector<int>> gd(k, vector<int>(3));

    for (int i = 0; i < k; i++) 
        cin >> gd[i][0] >> gd[i][1] >> gd[i][2];

    sort(gd.begin(), gd.end()); 

    for (int i = 0; i < k; i++) {
        int ops = gd[i][1];
        int cur_plant_store = gd[i][2];

        if (ops == 0) {
            if(store.empty()) {
                cout << 0 << endl;
                plant.push(cur_plant_store);
            } else {
                cout << store.front() << endl;
                store.pop();
            }
        } else {
            if(plant.empty()) {
                cout << 0 << endl;
                store.push(cur_plant_store);
            } else {
                cout << plant.front() << endl;
                plant.pop();
            }
        }
    }

    return 0;
}
