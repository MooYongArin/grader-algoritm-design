#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int n ,arr[102], dp[102][102], split[102][102];
void printOptimalParens(int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParens(i, split[i][j]);
        printOptimalParens(split[i][j] + 1, j);
        cout << ")";
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n + 1; i++) cin >> arr[i];

    for (int j = 1; j <= n; j++)
    {
        for (int i = j - 1; i >= 1; i--)
        {

            if(j - i == 1) {dp[i][j] = arr[i] * arr[i + 1] * arr[j + 1]; split[i][j] = i;}
            else if (i == j) dp[i][j] = 0;
            else {
                dp[i][j] = 1e9;
                for (int k = i; k <= j - 1; k++)
                {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
                    if(dp[i][j] > cost) {dp[i][j] = cost; split[i][j] = k;}
                }
                
            }

        }
        
    }
    cout << "Minimum cost: " << dp[1][n] << endl;
    cout << "Optimal parenthesization: ";
    printOptimalParens(1, n);
    
    return 0;
}