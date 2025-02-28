#include <bits/stdc++.h>

using namespace std;
int n, w, b;
void recur(int i, int height, string st){
    if(i == n) { cout << st << '\n'; return;}
    if(height - 1 >= 1) recur(i + 1, height - 1, st + "D");
    recur(i + 1, height, st + "S");
    if(height + 1 <= w) recur(i + 1, height + 1, st + "U");
}
int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(0);
    cin >> n >> w >> b;
    recur(0, b, "");
    return 0;
}