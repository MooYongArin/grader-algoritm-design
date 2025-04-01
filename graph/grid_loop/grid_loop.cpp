#include <bits/stdc++.h>
using namespace std;
int arr[1009][1009];
int vst[1009][1009];
int color = 1, sze;
bool dfs(int i, int j, int bf) // 1->w 2->a 3->s 4->d
{
    if (vst[i][j] == color)
        return true;
    vst[i][j] = color;
    ++sze;
    int next_i, next_j;
    if (arr[i][j] == 1)
    {
        next_i = i;
        next_j = j + 1;
        if ((arr[next_i][next_j] == 1 or arr[next_i][next_j] == 5 or arr[next_i][next_j] == 6) and bf != 4)
            return dfs(next_i, next_j, 2);
        next_i = i;
        next_j = j - 1;
        if ((arr[next_i][next_j] == 1 or arr[next_i][next_j] == 3 or arr[next_i][next_j] == 4) and bf != 2)
            return dfs(next_i, next_j, 4);
    }
    if (arr[i][j] == 2)
    {
        next_i = i + 1;
        next_j = j;
        if ((arr[next_i][next_j] == 2 or arr[next_i][next_j] == 3 or arr[next_i][next_j] == 6) and bf != 3)
            return dfs(next_i, next_j, 1);
        next_i = i - 1;
        next_j = j;
        if ((arr[next_i][next_j] == 2 or arr[next_i][next_j] == 4 or arr[next_i][next_j] == 5) and bf != 1)
            return dfs(next_i, next_j, 3);
    }
    if (arr[i][j] == 3)
    {
        next_i = i - 1;
        next_j = j;
        if ((arr[next_i][next_j] == 2 or arr[next_i][next_j] == 4 or arr[next_i][next_j] == 5) and bf != 1)
            return dfs(next_i, next_j, 3);
        next_i = i;
        next_j = j + 1;
        if ((arr[next_i][next_j] == 1 or arr[next_i][next_j] == 5 or arr[next_i][next_j] == 6) and bf != 4)
            return dfs(next_i, next_j, 2);
    }
    if (arr[i][j] == 4)
    {
        next_i = i;
        next_j = j + 1;
        if ((arr[next_i][next_j] == 1 or arr[next_i][next_j] == 5 or arr[next_i][next_j] == 6) and bf != 4)
            return dfs(next_i, next_j, 2);
        next_i = i + 1;
        next_j = j;
        if ((arr[next_i][next_j] == 2 or arr[next_i][next_j] == 3 or arr[next_i][next_j] == 6) and bf != 3)
            return dfs(next_i, next_j, 1);
    }
    if (arr[i][j] == 5)
    {
        next_i = i + 1;
        next_j = j;
        if ((arr[next_i][next_j] == 2 or arr[next_i][next_j] == 3 or arr[next_i][next_j] == 6) and bf != 3)
            return dfs(next_i, next_j, 1);
        next_i = i;
        next_j = j - 1;
        if ((arr[next_i][next_j] == 1 or arr[next_i][next_j] == 3 or arr[next_i][next_j] == 4) and bf != 2)
            return dfs(next_i, next_j, 4);
    }
    if (arr[i][j] == 6)
    {
        next_i = i - 1;
        next_j = j;
        if ((arr[next_i][next_j] == 2 or arr[next_i][next_j] == 4 or arr[next_i][next_j] == 5) and bf != 1)
            return dfs(next_i, next_j, 3);
        next_i = i;
        next_j = j - 1;
        if ((arr[next_i][next_j] == 1 or arr[next_i][next_j] == 3 or arr[next_i][next_j] == 4) and bf != 2)
            return dfs(next_i, next_j, 4);
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int R, C, ans = 0, loop = 0;
    cin >> R >> C;
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            if (!vst[i][j])
            {
                sze = 0;
                if (dfs(i, j, -1))
                {
                    ans = max(ans, sze);
                    ++loop;
                }
                ++color;
            }
        }
    }
    cout << loop << " " << ans << "\n";
}
