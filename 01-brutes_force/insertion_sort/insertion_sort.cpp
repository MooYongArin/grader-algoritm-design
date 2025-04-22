#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
void insertion_sort(vector<int> a, int &count, int k) {
    auto it = find(a.begin(), a.end(), k);
    int pos = it - a.begin();
    for (size_t i = 0; i < pos; i++) if (a[i] > k) count++;
}
int main(){
    
    cin >> n >> m;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) cin >> a[i];
    for (size_t i = 0; i < m; i++)
    {
        int k, count = 0;
        cin >> k;
        insertion_sort(a, count, k);
        cout << count << endl;
    }
    
    return 0;
}