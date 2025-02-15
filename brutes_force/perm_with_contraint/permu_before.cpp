#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<int> sol;
vector<bool> used;

void perm(int n, map<int, int> &m, int len)
{
    if (len < n) {
        for (int i = 0; i < n; i++) {
            if (used[i] == false && (m.find(i) == m.end() || used[m[i]] == true)) {
                used[i] = true;
                sol[len] = i;    
                perm(n, m, len + 1);
                used[i] = false;
            }
        }
    }
    else {
        for (auto &x : sol) cout << x << " ";
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b;
    cin >> n >> m;
    map<int, int> mp;
    for (size_t i = 0; i < m; i++)
    {
        cin >> a >> b;
        mp[b] = a;
    }

    sol.resize(n);
    used.resize(n);
    
    perm(n, mp, 0);
    return 0;
}