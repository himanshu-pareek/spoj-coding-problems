#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int C;
	scanf ("%d", &C);
	for (int c = 1; c <= C; c++) {
		printf ("Case #%d: ", c);
		// do something here
		int n, k, T; ll b;
		scanf ("%d %d %lld %d", &n, &k, &b, &T);
		vector < ll > x (n);
		for (ll & ele : x) scanf ("%lld", & ele);
		vector < int > v (n);
		for (int & ele : v) scanf ("%d", & ele);
		vector < ll > t (n);
		for (int i = 0; i < n; i++) {
			t[i] = ceil ((double) (b - x[i]) / v[i]);
		}
		vector < int > grt (n, -1);
		int countRight = 0;
		int countBigger = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (t[i] > T) {
				countBigger++;
			} else {
				countRight++;
				grt[i] = countBigger;
			}
		}
		if (countRight < k) {
			printf ("IMPOSSIBLE\n");
			continue;
		}
		int ans = 0;
		int i = n - 1;
		while (k > 0) {
			if (grt[i] >= 0) {
				ans += grt[i];
				k--;
			}
			i--;
		}
		printf ("%d\n", ans);
	}
	return 0;
}

