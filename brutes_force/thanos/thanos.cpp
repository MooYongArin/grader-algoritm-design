#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector <int> avenger_pos;
int n, k, A, B;

long long solve(long long  l, long long  r) {
	long long kol = upper_bound(avenger_pos.begin(), avenger_pos.end(), r) - avenger_pos.begin() - (lower_bound(avenger_pos.begin(), avenger_pos.end(), l) - avenger_pos.begin());

    // No avenger in range
	if (kol == 0) return A;

    // lenght = r - l + 1, kol = avenger in range
	long long  cur = (r - l + 1) * kol * B;
	if (l == r) return cur;

	long long  mid = (r + l) / 2;
	return min(cur, solve(l, mid) + solve(mid + 1, r));

}

int main() {

	cin >> n >> k >> A >> B;
	int p = (1 << n);
	for (int i = 0; i < k; i++) {
        // avenger pos
		int x;
		cin >> x;
		x--;
		avenger_pos.push_back(x);
	}
	sort(avenger_pos.begin(), avenger_pos.end());
	cout << solve(0, p - 1);



	return 0;

}
