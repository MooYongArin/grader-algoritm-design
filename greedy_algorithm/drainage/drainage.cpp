#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, l;
    cin >> n >> l;
    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i];
    
    sort(p, p + n);
    int sum = 1, right_border = p[0] + l;
    for (int i = 0; i < n; i++) {
        if(p[i] > right_border) {
            sum++;
            right_border = p[i] + l;
        }
    }
    cout << sum << endl;
    return 0;
}