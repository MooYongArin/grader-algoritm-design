#include"stdio.h"
#include"algorithm"
using namespace std;
int N, M, X, DP[1000005];
int firstNotLess(int X) {
	int lo = 1, hi = M + 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (DP[mid] >= X) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}
int main() {
	DP[1] = 1;
	DP[2] = 3;
	for (int i = 3, j = 2; ; i++) {
		if (i > DP[j]) j++;
		DP[i] = DP[i-1] + j;
		if (DP[i] > (int)(2e9)) {
			M = i;
			break;
		}
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		printf("%d\n", firstNotLess(X));
	}
}