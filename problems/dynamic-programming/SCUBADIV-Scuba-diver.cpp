#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int dp[1005][25][85];
const int INF = 1e9 + 5;

void min_self (int & a, int b) {
	if (a > b) a = b;
}

struct cylinder {
	int oxygen;
	int nitrogen;
	int weight;
};

void solve () {
	int t, a, n;
	scanf ("%d %d", &t, &a);
	scanf ("%d", &n);
	vector < cylinder > cylinders (n);
	for (cylinder & c : cylinders) scanf ("%d %d %d", & (c.oxygen), &(c.nitrogen), & (c.weight));
	for (int j = 0; j <= t; j++) {
		for (int k = 0; k <= a; k++) {
			dp[0][j][k] = INF;
		}
	}
	for (int i = 0; i < n; i++) {
		dp[i][0][0] = 0;
	}
	for (int i = 0; i < n; i++) {
		// fill dp[i + 1][][]
		
		// (1) Don't take i
		for (int j = 0; j <= t; j++) {
			for (int k = 0; k <= a; k++) {
				dp[i + 1][j][k] = dp[i][j][k];
			}
		}
		
		// (2) Take i
		for (int j = 0; j <= t; j++) {
			for (int k = 0; k <= a; k++) {
				min_self (dp[i + 1][j][k], dp[i][max (0, j - cylinders[i].oxygen)][max (0, k - cylinders[i].nitrogen)]
									+ cylinders[i].weight);
			}
		}
	}
	printf ("%d\n", dp[n][t][a]);
}

int main () {
	int c;
	scanf ("%d", & c);
	while (c--) {
		solve ();
	}
	return 0;
}
