#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, ans = 0;;
vector<pair<int, int>> v;

vector<int> pareto(int l,int r) {
    if(l == r) return {l};

    int m = (l+r) / 2;
    vector<int> left = pareto(l, m);
    vector<int> right = pareto(m + 1, r);

    vector<int> merged;
    int max_y = -1;

    for (int idx : right) {
        if (v[idx].second > max_y) {
            merged.push_back(idx);
            max_y = v[idx].second;
        }
    }
    for (int idx : left) {
        if (v[idx].second > max_y) {
            merged.push_back(idx);
            max_y = v[idx].second;
        }
    }
    return merged;
}
// ai.x > aj.x || ai.y > aj.y for every j (ai is perato)
int main(){
    cin >> n;
    v.resize(n);
    for (size_t i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    vector<int> frontier = pareto(0, n - 1);
    cout << frontier.size() << endl;
    return 0;
}