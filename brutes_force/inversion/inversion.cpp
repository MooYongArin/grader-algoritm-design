#include <bits/stdc++.h>

int res = 0;
int merge(std::vector<int> &v, std::vector<int> &a, int left, int middle, int right){
    int lp = left;
    int rp = middle + 1;

    for (size_t i = left; i <= right; i++)
    {
        if (rp > right) { a[i] = v[lp++]; continue; }
        if (lp > middle) { a[i] = v[rp++]; continue; }
        if(v[lp] <= v[rp]) {
            a[i] = v[lp++];
        } else {
            a[i] = v[rp++];
            res += middle - lp + 1;
        }
    }
    
    
    for (int i = left; i<= right;i++) v[i] = a[i];
    return res;
}
int merge_sort(std::vector<int> &v, std::vector<int> &a, int left, int right){
    if (right > left)
    {
        int middle = (left + right)/2;
        int left_inversion = merge_sort(v,a,left,middle);
        int right_inversion = merge_sort(v,a,middle+1,right);

        int cross_inversion = merge(v,a,left,middle,right);
        return left_inversion + right_inversion;
    }
    return 0;
}
int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n), k(n);
    for (size_t i = 0; i < n; i++) std::cin >> v[i];
    merge_sort(v,k,0,n-1);
    
    std::cout << res;
    
    return 0;
}