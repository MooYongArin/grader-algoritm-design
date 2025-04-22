#include <bits/stdc++.h>

using namespace std;

int n, a[1001];
int sequence[20000001]; // Array to store the self-describing sequence

int main() {
    cin >> n;
    int max_query = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        max_query = max(max_query, a[i]);
    }

    // Generate the self-describing sequence
    int current_number = 1;
    int index = 1;
    while (index <= max_query) {
        for (int i = 0; i < current_number; i++) {
            sequence[index++] = current_number;
            if (index > max_query) break;
        }
        current_number++;
    }

    // Answer the queries
    for (int i = 1; i <= n; i++) {
        cout << sequence[a[i]] << endl;
    }

    return 0;
}