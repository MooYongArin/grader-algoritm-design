#include <iostream>
#include <vector>

using namespace std;

int get_sum(vector<int> S,int a,int b) {
    return S[b] - S[a-1];
}

int find_max_sum(vector<int> &v, vector<int> &s, int start, int end){
    if (start == end) return v[start];

    int m = (start + end)/2;

    int r1 = find_max_sum(v, s, start, m);
    int r2 = find_max_sum(v, s, m+1, end);

    int max_sum_left = get_sum(s,m,m);
    for (size_t i = start; i < m; i++) max_sum_left = max(max_sum_left,get_sum(s,i,m));

    int max_sum_right = get_sum(s,m + 1,m + 1);
    for (size_t j = m + 2; j <= end; j++) max_sum_right = max(max_sum_right,get_sum(s,m+1,j));


    int r3 = max_sum_left + max_sum_right;

    return max(max(r1,r2),r3);
}

int main (){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, sum = 0;
    cin >> n;
    vector<int> a(n+1);
    vector<int> s(n+1);
    s[0] = 0;
    for (size_t i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        s[i] = sum;
    }

    cout << find_max_sum(a, s, 1, n);
    return 0;
}