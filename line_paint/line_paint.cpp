#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;
int main(){
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    cout << v[0].first << " ";
    int border = v[0].second;
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i].first > border + 1)
        {
            cout << border << " " << v[i].first << " ";
        }
        if(v[i].second > border) border = v[i].second;
    }
    cout << border << " ";
    
    
    return 0;
}