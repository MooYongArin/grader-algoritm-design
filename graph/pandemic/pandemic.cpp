#include <bits/stdc++.h>

using namespace std;
int main(){
    int r, c, t;
    cin >> r >> c >> t;
    int arr[r][c], infected = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 1) { q.push({i, j}); infected++; }
        }
    }
    queue<pair<int, int>> next_day_q;
    for (int i = 0; i < t; i++)
    {
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int a = p.first, b = p.second;
            if(arr[a + 1][b] == 0 && a + 1 < r) {
                next_day_q.push({a + 1, b});
                arr[a + 1][b] = 1;
                infected++;
            }
            if(arr[a][b + 1] == 0 && b + 1 < c) {
                next_day_q.push({a, b + 1});
                arr[a][b + 1] = 1;
                infected++;
            }
            if(arr[a - 1][b] == 0 && a - 1 >= 0) {
                next_day_q.push({a - 1, b});
                arr[a - 1][b] = 1;
                infected++;
            }
            if(arr[a][b - 1] == 0 && b - 1 >= 0) {
                next_day_q.push({a, b - 1});
                arr[a][b - 1] = 1;
                infected++;
            }
        }
        swap(q, next_day_q);
    }
    cout << infected << endl;
    return 0;
}