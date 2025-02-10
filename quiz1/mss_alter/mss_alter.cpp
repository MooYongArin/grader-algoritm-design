#include <iostream>
#include <vector>

using namespace std;
vector<int> a;
int n;
int mss(int start, int stop) {
    if(start == stop) return a[start];

    int m = (start+stop) / 2;

    int r1 = mss(start,m);
    int r2 = mss(m+1,stop);
    
    int sum_left = 0;
    int max_sum_left_odd = -1e9, max_sum_left_even = -1e9;
    bool neg = true;
    for (int p = m; p >= start; --p)
    {
        int x = a[p];
        if(neg) x = -x;
        sum_left += x;
        if ((m - p + 1) % 2 == 0) max_sum_left_even = max(max_sum_left_even, sum_left);
        else max_sum_left_odd = max(max_sum_left_odd, -sum_left);
        neg = !neg;
    }

    int sum_right = 0;
    int max_sum = -1e9;
    neg = false;
    for (int q = m+1; q <= stop; ++q)
    {
        int x = a[q];
        if(neg) x = -x;
        sum_right += x;
        
        max_sum = max(max(max_sum, max_sum_left_even + sum_right), max_sum_left_odd - sum_right);
        neg = !neg;
    }

    return max(max(r1, r2), max_sum);
}
int main(){
    cin >> n;
    a.resize(n);
    for (size_t i = 0; i < n; i++) cin >> a[i];
    cout << mss(0, n - 1) << endl;
    return 0;
}
