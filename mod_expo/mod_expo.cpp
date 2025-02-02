#include <iostream>
#include <vector>

using namespace std;
int modu_expo(int x, int n, int k){
    if(n == 1) return x % k;
    int p = modu_expo(x, n/2, k);
    p = (p*p)%k;
    if(n % 2 == 0) {
        return p;
    } else {
        return (p* (x%k))%k;
    }
}
int main(){
    int x, n, k;
    cin >> x >> n >> k;
    cout << modu_expo(x, n, k) << endl;
    return 0;
}