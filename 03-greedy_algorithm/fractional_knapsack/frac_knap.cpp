#include <bits/stdc++.h>

using namespace std;
int n;
double W, v[100001], w[100001];
int main(){
    cin >> W >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> w[i];

    vector<pair<double, pair<double, double>>> gd(n + 1); 
    for (int i = 1; i <= n; i++) {
        double ratio = v[i] / w[i];
        gd[i] = make_pair(ratio, make_pair(v[i], w[i]));
    }
    sort(gd.begin() + 1, gd.end());
    reverse(gd.begin() + 1, gd.end());

    double sum_price = 0, available_weight = W;
    for (int i = 1; i <= n; i++) {
        double price = gd[i].second.first, weight = gd[i].second.second;
        if(weight <= available_weight) {
            available_weight -= weight;
            sum_price += price;
        } else {
            double fraction = available_weight / weight;
            sum_price += (fraction * price);
            break;
        }
    }
    cout << fixed <<  setprecision(4) << sum_price << endl;
    return 0;
}