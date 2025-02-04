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

        int r = n - 1;
        int best_r = l, save_l = l;
        long long totalCost = 0;

        while (l <= r) {
            int mid = (r + l) / 2;
            long long grassSum = prefix[mid + 1] - prefix[l]; 
            long long cost = grassSum + (mid - l + 1) * k;

            if (cost > budget) {
                r = mid - 1;
            } else {
                best_r = mid;
                l = mid + 1;
            } 
        }

        cout << (prefix[best_r + 1] - prefix[save_l]) << "\n"; 
    }

    return 0;
}

