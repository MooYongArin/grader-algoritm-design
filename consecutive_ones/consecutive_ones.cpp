#include <iostream>
#include <vector>

using namespace std;
bool found_consec(string st, int k){
    int count = 0;
    for (char &ch : st)
    {
        if (ch == '1') count++;
        else count = 0;
        if(count == k) return true;
    }
    return false;
}
void consecutive_ones(int n, int k, string st){
    if(st.length() == n && found_consec(st, k)) cout << st << endl;
    if(st.length() > n) return;

    consecutive_ones(n, k, st + "0");
    consecutive_ones(n, k, st + "1");
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<string> str(n);
    consecutive_ones(n, k, "");
}