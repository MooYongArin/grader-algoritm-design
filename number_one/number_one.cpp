#include<bits/stdc++.h>
using namespace std;
int s[100];
int cal(int n,int l,int r,int level){
    int ret=0;
//    printf("%d %d %d %d\n",n,l,r,level);
    if(n==1)return 1;
    if(l<=s[level]){
        ret+=cal(n>>1,l,min(r,s[level]),level+1);
    }
    if(r>s[level]+1){
        ret+=cal(n>>1,max(l,s[level]+2)-s[level]-1,r-s[level]-1,level+1);
    }
    if(l<=s[level]+1 && s[level]+1<=r){
        ret+=n&1;
    }
//    printf("ret %d\n",ret);
    return ret;
}
void calS(int n,int level){
    if(n==1){
        s[level]=1;
        return;
    }
    calS(n>>1,level+1);
    s[level]=s[level+1]*2+1;
//    printf("%d %d\n",level,s[level]);
}
int main(){
    int n,l,r;
    cin>>n>>l>>r;
    calS(n,0);
    cout<<cal(n,l,r,1);
}

