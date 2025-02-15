#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> y;

int street(long long a, long long b, long long c) {
    int res = upper_bound(y.begin(), y.end(), c) - lower_bound(y.begin(), y.end(), b);

    if (res == 0) return 0;
    if (c - b + 1 < 3) return res;

    long long u = (c - b + 1) / 3;
    long long v = (c - b + 2) / 3;

    int p1 = street(a+1, b, b + u - 1);
    int p2 = street(a+2, b + u, b + u + v - 1);
    int p3 = street(a+3, b + u + v, c);

    // เลือก r1, r2 ที่ max
    return res + p1 + p2 + p3 - min(min(p1,p2),p3);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long w;
    cin >> w >> n;
    y.resize(n);

    for (int i = 0; i < n; i++) cin >> y[i];

    sort(y.begin(), y.end());
    
    cout << street(0,1,w) << endl;
    return 0;
}
