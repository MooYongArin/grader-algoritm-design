#include <iostream>
#include <vector>

using namespace std;

bool contain_k_ones(int k, string st){
    int count = 0;
    for (char &ch : st) if(ch == '1') count++;
    return count == k;
}
void gen_bar(int n,int k, string st){
    if(st.length() == n && contain_k_ones(k, st)) cout << st << endl;
    if(st.length() > n) return;
    
    gen_bar(n, k, st + "0");
    gen_bar(n, k, st + "1");
}
int main(){
    int n, k;
    cin >> k >> n;
    gen_bar(n,k, "");
    return 0;
}