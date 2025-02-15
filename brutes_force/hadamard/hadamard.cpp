#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> v;
vector<int> res;
void process(int st,int en,vector<int> &ans){
    if(st==en)
    {
        ans.push_back(v[st]);
        return;
    }
    int mid=(st+en)/2;
    vector<int> left_ans,right_ans;

    process(st,mid,left_ans);
    process(mid+1,en,right_ans);


    for(int i = 0; i < left_ans.size(); i++)
        ans.push_back(left_ans[i] + right_ans[i]);
    for(int i = 0; i < left_ans.size(); i++)
        ans.push_back(left_ans[i] - right_ans[i]);    
}
int main(){
    cin >> n;
    v.resize(n);
    for (size_t i = 0; i < n; i++) cin >> v[i];
    process(0, n-1, res);
    for (int &i : res) cout << i << " ";
    
    return 0;
}