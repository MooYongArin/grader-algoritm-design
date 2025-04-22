#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> A(n);
    vector<long long> prefix(n + 1, 0); 
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        prefix[i + 1] = prefix[i] + A[i]; 
    }
    
    while (m--) {
        int l;
        long long budget;
        cin >> l >> budget;
        if (A[l] + k > budget)
        {
            cout << 0 << endl;
            continue;
        }
        
        int lo = l, hi = n - 1, best_r = l;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            long long grassSum = prefix[mid + 1] - prefix[l]; 
            long long cost = grassSum + (mid - l + 1) * k; 

            if (cost <= budget) {
                best_r = mid; 
                lo = mid + 1;  
            } else {
                hi = mid - 1; 
            }
        }

        cout << (prefix[best_r + 1] - prefix[l]) << "\n"; 
    }

    return 0;
}

