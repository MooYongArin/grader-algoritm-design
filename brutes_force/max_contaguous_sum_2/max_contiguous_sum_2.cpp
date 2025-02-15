#include <iostream>
#include <vector>

using namespace std;
int n, total_sum = 0;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    v.resize(n);
    for (size_t i = 0; i < n; i++) {
        cin >> v[i];
        total_sum += v[i];
    }

    int sum = v[0];
    int max_sum = v[0];

    for (size_t i = 1; i < n; i++)
    {
        if(sum <= 0) sum = v[i];
        else sum += v[i];

        if(sum > max_sum) max_sum = sum;
    }

    sum = v[0];
    int min_sum = v[0];
    for (int i = 1; i < n; i++) {
        sum = min(v[i], sum + v[i]);
        min_sum = min(min_sum, sum);
    }

    if (min_sum == total_sum) {
        cout << max_sum << endl;
    } else {
        cout << max(max_sum, total_sum - min_sum) << endl;
    }
    
    return 0;
}