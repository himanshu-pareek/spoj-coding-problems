#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void max_self (int & a, int b) {
	if (b > a) a = b;
}

char s1[1001];
char s2[1001];
int dp[1001][1001][2];
int same[1001][1001];

void solve (int k) {
	// string s1, s2;
	//cin >> s1 >> s2;
	scanf ("%s %s", s1, s2);
	//cout << s1 << endl << s2 << endl;
	const int m = strlen (s1);
	const int n = strlen (s2);
	int answer = 0;
	int start_j = 0;
	//vector < vector < int > > same (m + 1, vector < int > (n + 1, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			same[i + 1][j + 1] = (s1[i] == s2[j]) ? 1 + same[i][j] : 0;
		}
	}
	//vector < vector < vector < int > > > dp (m + 1, vector < vector < int > > (n + 1, vector < int > (2, 0)));
	/*
	 * dp[i][j][0] = Length of LCS with all segments except last one >= k (but ending at i, j)
	 *
	 * dp[i][j][1] = Original Constraints (ending at i, j)
	 */

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			dp[i + 1][j + 1][0] = dp[i + 1][j + 1][1] = max (dp[i][j + 1][1], dp[i + 1][j][1]);
			// update dp[i + 1][j + 1][0]
			if (s1[i] == s2[j]) {
				max_self (dp[i + 1][j + 1][0], 1 + dp[i][j][0]);
			}

			// Update dp[i + 1][j + 1][1]
			if (s1[i] == s2[j]) {
				if (same[i + 1][j + 1] >= k) {
					max_self (dp[i + 1][j + 1][1], k + dp[i - k + 1][j - k + 1][0]);
				}
			}
		}
	}
	printf ("%d\n", dp[m][n][1]);
}

int main() {
	int k;
	while (true) {
		scanf ("%d", &k);
		//cout << k << endl;
		if (k == 0) break;
		solve (k);
	}
	return 0;
}
