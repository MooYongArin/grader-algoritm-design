#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int c[m], t[m], suf_t[m], a, b;
    for (int i = 0; i < m; i++) cin >> c[i];
    for (int i = 0; i < m; i++) {
        cin >> t[i];
        if(i != 0) suf_t[i] = suf_t[i - 1] + t[i];
        else suf_t[i] = t[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        int sum_left = 0, sum_right = 0;
        for (int i = 0; i < m; i++) {
            if(a <= max(c[i], c[i + 1]) && a >= min(c[i], c[i + 1])){
                if(c[i] == 0) sum_right += suf_t[c[i + 1] - 1] - t[a];
                else sum_right += suf_t[c[i + 1] - 1] - suf_t[c[i] - 1] - t[a];
            } else {
                if(c[i] == 0) sum_right += suf_t[c[i + 1] - 1];
                else sum_right += suf_t[c[i + 1] - 1] - suf_t[c[i] - 1];
            }
            cout << sum_right << " ";
        }

        for (int i = 0; i < m; i++) {
            if(b <= max(c[i], c[i + 1]) && b >= min(c[i], c[i + 1])){
                if(c[i] == 0) sum_left += suf_t[c[i + 1] - 1] - t[b];
                else sum_left += suf_t[c[i + 1] - 1] - suf_t[c[i] - 1] - t[b];
            } else {
                if(c[i] == 0) sum_left += suf_t[c[i + 1] - 1];
                else sum_left += suf_t[c[i + 1] - 1] - suf_t[c[i] - 1];
            }
            cout << sum_left << " ";
        }

        // cout << min(sum_left, sum_right) << '\n';
    }

    return 0;
}