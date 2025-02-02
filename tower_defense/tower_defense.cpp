#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void attack(vector<int> &p, vector<int> &h, vector<int> &t, int t_idx, int w, int damage, int &max_damage){
    if(t_idx == t.size()) if(damage > max_damage) max_damage = damage;
    if(t_idx > t.size()) return;

    for (size_t i = 0; i < p.size(); i++)
    {
        // cout << t[t_idx] << p[i];
        if (p[i] >= t[t_idx] - w && p[i] <= t[t_idx] + w && h[i] > 0) {
            h[i] -= 1;
            attack(p, h, t, t_idx + 1, w, damage + 1, max_damage);
            h[i] += 1;
        }
    }
    attack(p, h, t, t_idx + 1, w, damage, max_damage);
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int n, m, k, w, total_health = 0, max_damage = 0;;
    cin >> n >> m >> k >> w;
    vector<int> p(m), h(m), t(k), damages;
    for (size_t i = 0; i < m; i++) cin >> p[i];
    for (size_t i = 0; i < m; i++) {
        cin >> h[i];
        total_health += h[i];
    }
    for (size_t i = 0; i < k; i++) cin >> t[i];
    attack(p, h, t, 0, w, 0, max_damage);
    cout << total_health - max_damage << endl;
    
    return 0;
}