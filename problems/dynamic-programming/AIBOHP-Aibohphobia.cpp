#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve() {
	string s;
	cin >> s;
	const int n = (int) s.size();
	vector < vector < int > > dp (n, vector < int > (n, 0));
	for (int i = 0; i < n - 1; i++) {
		dp[i][i] = 0;
		dp[i][i + 1] = (int) (s[i] != s[i + 1]);
	}
	dp[n - 1][n - 1] = 1;
	for (int len = 3; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			if (s[i] == s[j]) {
				dp[i][j] = dp[i + 1][j - 1];
			} else {
				dp[i][j] = 1 + min (dp[i][j - 1], dp[i + 1][j]);
			}
		}
	}
	printf ("%d\n", dp[0][n - 1]);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
