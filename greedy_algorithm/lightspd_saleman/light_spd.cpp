#include <bits/stdc++.h>

using namespace std;
// copy of hof
int v[1010],w[1010],s;
int dist(int a,int b) {
	int t = abs(w[a-1]-w[b-1]);
	return min(t,s-t);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> v[i];
    v[m] = v[0];
    for (int i = 0; i < m; i++)
    {
        cin >> w[i];
        s += w[i];
    }
    for (int i = 1; i < m; i++)
        w[i] += w[i - 1];
    for (int i = 0; i < n; i++)
    {
        int a, b, ans = 0, k = v[0];
        cin >> a >> b;
        for (int j = 0; j <= m; j++)
        {
            ans += min(dist(k, v[j]), min(dist(k, a) + dist(b, v[j]), dist(k, b) + dist(a, v[j])));
            k = v[j];
        }
        cout << ans << "\n";
    }

    return 0;
}