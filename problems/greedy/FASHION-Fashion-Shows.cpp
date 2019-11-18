#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
	int n;
	scanf ("%d", &n);
	vector < int > men (n), women (n);
	for (int & x : men) scanf ("%d", & x);
	for (int & x : women) scanf ("%d", & x);
	sort (men.begin(), men.end());
	sort (women.begin(), women.end());
	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer += men[i] * women[i];
	}
	printf ("%d\n", answer);
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
