#include <iostream>
#include <vector>
#include <set>

using namespace std;
void use_student(set<int> &days_needed, int count, int &min_st, vector<set<int>> &students, int available){
    if(available == 0) if(count < min_st) min_st = count;
    
}
int main(){
    int n, m;
    cin >> n >> m;
    int k, min_st = 0;
    vector<set<int>> v(m);
    set<int> days_needed;
    for (int i = 1; i <= n; ++i) days_needed.insert(i);

    for (size_t i = 0; i < m; i++) {
        cin >> k;
        while (k--) {
            int a;
            cin >> a;
            v[i].insert(a);
        }
    }
    use_student(days_needed, 0, min_st, v, n);
    cout << min_st << endl;
    
    
    return 0;

}