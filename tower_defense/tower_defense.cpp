#include <iostream>
#include <vector>

using namespace std;

void attack(vector<int> &p, vector<int> &h, vector<int> &t, int t_idx, int w, int damage, vector<int> &damages){
    if(t_idx == t.size()) damages.push_back(damage);
    for (size_t i = 0; i < h.size(); i++)
    {
        if (p[i] >= t[t_idx] - w && p[i] <= t[t_idx] + w && h[i] > 0) {
            h[i] -= 1;
            attack(p, h, t, t_idx + 1, w, damage + 1, damages);
            h[i] += 1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int n, m, k, w, total_health = 0;
    cin >> n >> m >> k >> w;
    vector<int> p(m), h(m), t(k), damages;
    for (size_t i = 0; i < m; i++) cin >> p[i];

    for (size_t i = 0; i < m; i++) {
        cin >> h[i];
        total_health += h[i];
    }
    for (size_t i = 0; i < k; i++) cin >> t[i];
    attack(p, h, t, 0, w, 0, damages);
    for (auto &i : damages) cout << total_health - i << " ";
    
    // cout << total_health - damage << endl;
    // cout << damage;
    return 0;
}