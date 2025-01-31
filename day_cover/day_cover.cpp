#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool isValid(vector<bool> &available){
    for (bool day : available) {
        if (!day) return false;
    }
    return true;
}
void day_cover(int count, int& min_st, vector<vector<int>>& students, vector<bool>& available, int index, int n) {
    if(count >= min_st) return;
    if(n == available.size()) {
        if (isValid(available)) {
            min_st = min(min_st, count);
            return;
        }
    }

    if (index >= students.size()) return;

    vector<int> days_covered;
    for (int& day : students[index]) {
        if (!available[day - 1]) {
            available[day - 1] = true;
            days_covered.push_back(day);
            n += 1;
        }
    }
    if (!days_covered.empty()) {
        day_cover(count + 1, min_st, students, available, index + 1, n);
    }
    for (int &day : days_covered) {
        available[day - 1] = false;
        n--;
    }

    day_cover(count, min_st, students, available, index + 1, n);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int min_st = m;

    vector<vector<int>> v(m);
    vector<bool> available(n, false);

    for (size_t i = 0; i < m; i++) {
        int k;
        cin >> k;
        while (k--) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    sort(v.begin(), v.end());
    day_cover(0, min_st, v, available, 0, 0);
    cout << min_st << endl;
    
    
    return 0;

}