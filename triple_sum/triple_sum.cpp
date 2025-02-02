#include <iostream>
#include <vector>

using namespace std;

int n, m, target;
vector<int> a;
int sum = 0;
bool isTripleSum(int i, int j, int k){
    if(j >= k) return false;
    sum = a[i] + a[j] + a[k];
    if(sum == target) return true;
    if(sum < target) return isTripleSum(i, j + 1, k);
    if(sum > target) return isTripleSum(i, j, k - 1);

}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin >> n >> m;
    a.resize(n);
    for (size_t i = 0; i < n; i++) cin >> a[i];
    while (m--)
    {
        cin >> target;
        bool isBreak = false;
        for (int i = 0; i < n - 2; i++) {
            if (isTripleSum(i, i + 1, n - 1)) {
                cout << "YES" << endl;
                isBreak = true;
                break;
            }
        }
        if(!isBreak) cout << "NO" << endl;
    }
    
    return 0;
}