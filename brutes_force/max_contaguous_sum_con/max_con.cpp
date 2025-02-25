#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int max_sum = INT_MIN;
    int current_sum = 0;

    // Calculate the sum of the first window
    for (int i = 0; i < w && i < n; i++) {
        current_sum += v[i];
    }
    max_sum = current_sum;

    // Slide the window across the array
    for (int i = w; i < n; i++) {
        current_sum += v[i] - v[i - w];
        max_sum = max(max_sum, current_sum);
    }

    // Check for subarrays of length less than w
    for (int i = 1; i < w && i < n; i++) {
        current_sum = 0;
        for (int j = 0; j < i; j++) {
            current_sum += v[j];
        }
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << endl;
    return 0;
}