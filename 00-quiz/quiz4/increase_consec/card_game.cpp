#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main(){ 
    int n;
    unordered_map<int, int> um;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        um[arr[i]]++;
    }
    
    unordered_map<ll, ll> mp; // amount, amount of amount
    for (auto &p : um) mp[p.second]++;

    ll score = 0;
    for (auto &p : mp) if(p.first > 1) score += (p.second * (p.first* p.first));

    cout << score;
    return 0;
}