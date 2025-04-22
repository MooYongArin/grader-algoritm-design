#include <bits/stdc++.h>

using namespace std;
int n, m, l[1002][1002], maxN = 0;
string str1, str2, a = "";
int main(){
    cin >> n >> m >> str1 >> str2;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) {
        cin >> l[i][j];
        if(l[i][j] > maxN) {
            a += str2[j - 1];
            maxN = l[i][j];
        }
    }

    cout << a << endl;
    
    
    
    return 0;
}