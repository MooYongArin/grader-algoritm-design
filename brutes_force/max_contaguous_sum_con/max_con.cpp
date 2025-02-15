#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, w;
    cin >> n >> w;

    vector<int> v(n);
    for (size_t i = 0; i < n; i++) cin >> v[i];

    int max_max_sum = v[0];
    int x, max_sum, sum;
    for (size_t i = 0; i < n; i++)
    {
        max_sum = v[i];
        sum = v[i];
        for (size_t j = 1; j < w; j++)
        {
            if(i + j >= n) break;
            x = v[i + j];
            if(sum <= 0) sum = x;
            else sum += x;
            max_sum = max(max_sum, sum);
        }
        max_max_sum = max(max_max_sum, max_sum);
    }
    cout << max_max_sum << endl;
    return 0;
}