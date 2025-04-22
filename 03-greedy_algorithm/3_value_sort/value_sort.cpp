#include <bits/stdc++.h>

using namespace std;
// copy of hof
int main(){
    int n;
    cin >> n;
    int arr[n], tmp[n];
    for (int i = 0; i < n; i++) { cin >> arr[i]; tmp[i] = arr[i];}
    sort(tmp, tmp + n);

    int cnt_unsort = 0, cnt_sort = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > tmp[i]) cnt_unsort++;
        if(arr[i] < tmp[i]) cnt_sort++;
    }
    
    cout << max(cnt_unsort, cnt_sort) << '\n';
    return 0;
}