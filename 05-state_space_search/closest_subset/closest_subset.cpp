#include <bits/stdc++.h>

using namespace std;
int n, m, k, arr[101], min_dif = INT_MAX;
vector<bool> used(101, false);
vector<int> prefix;
int max_sum(int idx,int remain) {
    if (idx >= n) return 0;
    if (idx == 0)
      return prefix[idx+remain-1];
    return prefix[idx+remain-1] - prefix[idx-1];
  }
  
  int min_sum(int idx,int remain) {
    if (idx >= n) return 0;
    if (remain == n) return prefix[n-1];
    return prefix[n-1] - prefix[n-1-remain];
  }
  
  int heuristic(int idx,int chosen,int sum) {
    int remain = m-chosen;
    int max_value = sum + max(0,max_sum(idx,remain));
    int min_value = sum + min(0,min_sum(idx,remain));
    if (k < min_value) return min_value - k;
    if (k > max_value) return k - max_value;
    return 0;
  }

void recur(int idx, int chosen, int sum){
    if(idx >= n) return;
    if(chosen == m) {
        min_dif = min(min_dif, abs(sum - k));
        return;
    }
    if (heuristic(idx,chosen,sum) > min_dif) return;    
    used[idx] = true;
    recur(idx + 1, chosen + 1, sum + arr[idx]);

    used[idx] = false;
    recur(idx + 1, chosen, sum);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    prefix.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    prefix[0] = arr[0];
    for (int i = 1;i < n;i++) prefix[i] = prefix[i-1]+arr[i];
    recur(0, 0, 0);
    cout << min_dif << '\n';
    return 0;
}
/*
4 2 10
1 4 2 3

3
*/