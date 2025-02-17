#include <bits/stdc++.h>

using namespace std;
int n, a[1000][1000];
int max_diag = -1000;
void diag_sum(int i, int j){
    if(j == n) return;

    int p = 1, sum = a[i][j], max_sum = a[i][j];
    while (i + p < n && j + p < n)
    {
        sum = max(a[i + p][j + p], sum + a[i + p][j + p]);
        max_sum = max(max_sum, sum);
        ++p;
    }

    max_diag = max(max_diag, max_sum);
    if(i != 0) diag_sum(i - 1, j);
    else diag_sum(0, j + 1);
}
int main(){
    cin >> n;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++) 
            cin >> a[i][j];

    diag_sum(n-1, 0);
    cout << max_diag << endl;
    return 0;
}