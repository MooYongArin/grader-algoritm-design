#include <bits/stdc++.h>

#define ll long long
using namespace std;
int main(){
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr, arr+n);
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = upper_bound(arr + i, arr + n, arr[i] + d) - arr - 1;
        cnt += idx - i;
    }
    cout << cnt << endl;
    return 0;
}