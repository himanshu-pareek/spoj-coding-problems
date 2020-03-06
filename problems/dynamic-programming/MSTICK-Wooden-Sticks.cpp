#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

struct stick {
	int length;
	int weight;
	bool operator < (const stick s) {
		if (length == s.length) {
			return weight < s.weight;
		}
		return length < s.length;
	}
};

void solve () {
	int n;
	scanf ("%d", &n);
	vector < stick > sticks (n);
	for (stick & s : sticks) scanf ("%d %d", & (s.length), & (s.weight));
	sort (sticks.begin(), sticks.end());
	vector < stick > rest;
	rest.push_back (sticks[0]);
	for (int i = 1; i < n; i++) {
		stick s = sticks[i];
		int l = 0, r = (int) rest.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (rest[mid].weight <= s.weight) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (l == rest.size()) {
			rest.push_back (s);
		} else {
			rest[l] = s;
		}
	}
	printf ("%d\n", (int) rest.size());
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
