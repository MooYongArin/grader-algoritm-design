#include <iostream>
#include <vector>

using namespace std;
int n, a, sum = 0;
vector<int> chef;

// at t time | served cnt people
long long served_at(long long t) {
	long long cnt = n; // The first N customers sit at t=0
	for (int i = 0; i < n; i++)
		cnt += t / chef[i]; // Count how many customers were served by each chef
	return cnt;
}
int main(){
    cin >> n >> a;
    chef.resize(n);
    for (size_t i = 0; i < n; i++) {
        cin >> chef[i];
        sum += chef[i];
    }

    for (int i = 0; i < a; i++) {
        long long c, res = 0, a = 0, b = -1;
        cin >> c;
        b = c * sum;
        while (a <= b) {
            long long m = (a + b) / 2;
            long long served_at_m = served_at(m), served_at_m_1 = served_at(m - 1);
            if (m == 0 || (served_at_m >= c && served_at_m_1 < c)) {
                res = m;
                break;
            }
            if (served_at_m < c) {
                a = m + 1;
            } else {
                b = m - 1;
            }
        }
        cout << res << endl;
    }
    
    
    return 0;
}