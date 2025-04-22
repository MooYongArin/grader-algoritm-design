#include <bits/stdc++.h>

using namespace std;
int main(){
    int r, c, k;
    cin >> r >> c >> k;
    int arr[r][c];
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 1) q.push({i, j});
        }
        
    }
    for (int i = 0; i < k; i++)
    {
        queue<pair<int, int>> new_q;
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int a = p.first, b = p.second;
            if(a + 1 < r && arr[a + 1][b] == 0) {
                arr[a + 1][b] = 2;
                new_q.push({a + 1, b});
            }
            if(b + 1 < c && arr[a][b + 1] == 0) {
                arr[a][b + 1] = 2;
                new_q.push({a, b + 1});
            }
            if(a - 1 >= 0 && arr[a - 1][b] == 0) {
                arr[a - 1][b] = 2;
                new_q.push({a - 1, b});
            }
            if(b - 1 >= 0 && arr[a][b - 1] == 0) {
                arr[a][b - 1] = 2;
                new_q.push({a, b - 1});
            }
        }
        swap(q, new_q);
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    
    return 0;
}