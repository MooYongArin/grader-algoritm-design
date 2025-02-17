#include <bits/stdc++.h>
using namespace std;
int n, m, sum = 0, chef[1000001];

// at t time | served cnt people
long long served_at(long long t) {
    if(t == 0) return n;
	long long cnt = n; // The first N customers sit at t=0
	for (int i = 0; i < n; i++)
		cnt += t / chef[i]; // Count how many customers were served by each chef
	return cnt;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin >> n >> m;
    for (size_t i = 0; i < n; i++) {
        cin >> chef[i];
        sum += chef[i];
    }
    for (size_t i = 0; i < n; i++) cout << 0 << "\n";
    int customer_cnt = n;
    if(n >= m) return 0;
    for (size_t i = 1, k = 1; i < m * sum; i++)
    {
        // cout << "TEST";
        int amount = served_at(i) - served_at(i - 1);
        // cout << amount << endl;
        for (size_t j = 0; j < amount; j++) {
            cout << k << "\n";
            customer_cnt++;
            if(customer_cnt == m) return 0;
        }
        ++k;
    }
    return 0;
}