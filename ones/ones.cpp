//This is not my own job. It is for education only.

#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int mn;

void rec( int a , int k ,  int ans )
{
    //printf("%d\n",a);
    if ( a < 11 )
    {
        if ( a <= 6 )   ans+=a;
        else    ans += (13-a);
        mn = min(mn,ans);
        return;
    }
    int number=1;
    for ( int c=1 ; c<=k-1 ; c++ )
    {
        number*=10;
        number++;
    }
    rec(a-number*(a/number),k-1,ans+k*(a/number));
    rec(number*((a/number)+1)-a,k-1,ans+k*((a/number)+1));


}
int main()
{
    mn = 1000;
    int n;
    scanf("%d",&n);
    int number=11,co=2;
    while(number < n)
    {
        number*=10;
        number++;
        co++;
    }
    //printf("%d\n",co);
    rec(number-n,co,co);
    rec(n,co-1,0);
    printf("%d",mn);
}


