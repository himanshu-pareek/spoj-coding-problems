#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", & x);
	sort (a.begin(), a.end());
	int index = -1;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == 2 && a[i + 1] == 3 && i == n - 2) {
			swap (a[i], a[i + 1]);
			index = i;
			break;
		}
		if (a[i] >= 2) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		reverse (a.begin() + index, a.end());
	}
	for (int x : a) {
		printf ("%d ", x);
	}
	printf ("\n");
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
