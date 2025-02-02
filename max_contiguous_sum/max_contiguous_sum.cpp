#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n ;
    vector<int> v(n);
    for (size_t i = 0; i < n; i++) cin >> v[i];
    
    int sum =  v[0];
    int max_sum = v[0];
    
    for(int i = 1;i < n; i++){
        if(sum <= 0) sum = v[i]; 
        else sum += v[i];

        if(sum > max_sum) max_sum = sum;
    }

    cout << max_sum;
}

