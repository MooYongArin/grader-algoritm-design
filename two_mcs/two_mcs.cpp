#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    cin >> n;
    v.resize(n);
    for (size_t i = 0; i < n; i++) cin >> v[i];
    vector<int> best1(n), best2(n);

    int sum = v[0], max_sum = v[0];
    best1[0] = v[0];
    for (size_t i = 1; i < n; i++) {
        if (sum <= 0) sum = v[i];
        else sum += v[i];
        if(sum > max_sum) max_sum = sum;
        best1[i] = max_sum;
    }

    int sum_2 = v[n-1], max_sum_2 = v[n-1];
    best2[n-1] = v[n-1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (sum_2 <= 0) sum_2 = v[i];
        else sum_2 += v[i];
        if(sum_2 > max_sum_2) max_sum_2 = sum_2;
        best2[i] = max_sum_2;
    }
    int result = max_sum;
    for (size_t i = 0; i < n - 1; i++) {
        result = max(result, best1[i] + best2[i + 1]);
    }
    cout << result << endl;
    return 0;
}