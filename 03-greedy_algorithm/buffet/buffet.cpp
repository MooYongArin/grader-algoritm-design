#include <bits/stdc++.h>

using namespace std;
int main(){
    int f, w, n, a[10001];
    cin >> f >> w >> n;
    for (int i = 0; i < f; i++) cin >> a[i];
    sort(a, a + f);
    int right_border = a[0] + 2*w, sum_select = 1;
    for (int i = 1; i < f; i++) {
        if(a[i] > right_border) {
            sum_select++;
            right_border = a[i] + 2*w;
        }
        
    }
    cout << sum_select << endl;
    return 0;
}