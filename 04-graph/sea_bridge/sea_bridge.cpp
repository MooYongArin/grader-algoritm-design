#include <bits/stdc++.h>

using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);
    int r, c;
    cin >> r >> c;
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
    int cnt = 1;
    bool isBreak = false;
    while (true)
    {
        queue<pair<int, int>> new_q;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int a = p.first, b = p.second;
            if(a + 1 < r && (arr[a + 1][b] == 0 || arr[a + 1][b] == 2)) {
                if(arr[a + 1][b] == 2) {
                    isBreak = true;
                    break;
                }
                arr[a + 1][b] = 1;
                new_q.push({a + 1, b});
            }
            if(b + 1 < c && (arr[a][b + 1] == 0 || arr[a][b + 1] == 2)) {
                if(arr[a][b + 1] == 2) {
                    isBreak = true;
                    break;
                }
                arr[a][b + 1] = 1;
                new_q.push({a, b + 1});
            }
            if(a - 1 >= 0 && (arr[a - 1][b] == 0 || arr[a - 1][b] == 2)) {
                if( arr[a - 1][b] == 2) {
                    isBreak = true;
                    break;
                }
                arr[a - 1][b] = 1;
                new_q.push({a - 1, b});
            }
            if(b - 1 >= 0 && (arr[a][b - 1] == 0 || arr[a][b - 1] == 2)) {
                if(arr[a][b - 1] == 2) {
                    isBreak = true;
                    break;
                }
                arr[a][b - 1] = 1;
                new_q.push({a, b - 1});
            }
        }
        cnt++;
        if(isBreak) break;
        swap(q, new_q);
    }
    
    cout << cnt << '\n';
    
    return 0;
}