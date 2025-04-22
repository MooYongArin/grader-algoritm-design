#include <bits/stdc++.h>

using namespace std;
// copy of hof

int N, D, h[100001], i, l, r, m, k, d, md;

int main()
{
    cin >> N >> D;
    for(i=1; i<=N; i++){cin>>h[i]; l=max(l, h[i]-h[i-1]);}
    r = h[N]+1;
    while(l < r){
        m = (l+r)/2;
        k = d = 0;
        for(i=1; i<=N; i++) if(k+m<h[i+1] || i==N){k=h[i]; d++;}
        if(d <= D){r=m; md=max(md, d);}
        else l=m+1;
    }
    cout << r << " " << md;
}

/*
9 3
10 30 50 70 90 110 120 170 180
*/