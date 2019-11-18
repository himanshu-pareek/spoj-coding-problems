#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void max_self (ll & a, ll b) {
	a = max (a, b);
}

int main() {
	int n;
	scanf ("%d", &n);
	while (n != -1) {
		vector < ll > a (n);
		for (ll & x : a) scanf ("%lld", & x);
		ll sum = 0;
		for (ll x : a) sum += x;
		if (sum  % n) {
			printf ("-1\n");
			scanf ("%d", &n);
			continue;
		}
		int count = 0;
		ll how_many = sum / n;
		for (ll & x : a) x -= how_many;
		ll answer = abs (a[0]);
		for (int i = 1; i < n; i++) {
			a[i] += a[i - 1];
			max_self (answer, abs (a[i]));
		}
		printf ("%lld\n", answer);
		scanf ("%d", &n);
	}
	return 0;
}
