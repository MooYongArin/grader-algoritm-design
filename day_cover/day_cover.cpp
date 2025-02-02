#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;

void day_cover(int count, int& min_st, vector<vector<int>>& students, vector<int>& available, int index, int tmp) {
    if(tmp == n) {
        min_st = min(min_st, count);
        return;
    }
    if(count >= min_st) return;
    if(index == m) return;

    for (int &day : students[index]) {
        if (available[day - 1] == 0) tmp++;
        available[day - 1]++;
    }
    
    day_cover(count + 1, min_st, students, available, index + 1, tmp);

    for (int &day : students[index]) {
        available[day - 1]--;
        if (available[day - 1] == 0) tmp--;
    }

    day_cover(count, min_st, students, available, index + 1, tmp);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin >> n >> m;
    int min_st = m;

    vector<vector<int>> v(m);
    vector<int> available(n, 0);

    for (size_t i = 0; i < m; i++) {
        int k;
        cin >> k;
        while (k--) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    day_cover(0, min_st, v, available, 0, 0);
    cout << min_st << endl;
    
    
    return 0;

}
