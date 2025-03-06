#include <bits/stdc++.h>
using namespace std;

int minSwapsToBalance(string T, int n) {
    int balance = 0;
    int swaps = 0;
    int open_needed = 0;
    vector<int> misplaced_close_indices;

    // First pass to find all misplaced closing parentheses
    for (int i = 0; i < n; ++i) {
        if (T[i] == '(') {
            balance++;
        } else {
            balance--;
        }

        // If balance is negative, we have more ')' than '(' up to this point
        if (balance < 0) {
            misplaced_close_indices.push_back(i);
            balance = 0; // Reset balance after counting the needed '('
        }
    }

    // Second pass to calculate the minimum swaps needed
    int j = 0; // Pointer for misplaced closing parentheses
    balance = 0;
    for (int i = 0; i < n; ++i) {
        if (T[i] == '(') {
            balance++;
        } else {
            balance--;
        }

        // If balance is negative, we need to swap
        if (balance < 0) {
            swaps += misplaced_close_indices[j] - i;
            j++;
            balance = 0; // Reset balance after swap
        }
    }

    return swaps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string T;
    cin >> T;
    int n = T.length();

    int result = minSwapsToBalance(T, n);
    cout << result << endl;

    return 0;
}