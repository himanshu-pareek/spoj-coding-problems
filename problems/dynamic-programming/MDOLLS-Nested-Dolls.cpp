#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

struct doll {
	int width, height;
	//doll (int w, int h) {
		//width = w;
		//height = h;
	//}
	bool operator < (const doll & d) {
		if (width == d.width) {
			return height < d.height;
		}
		return width > d.width;
	}
};

void solve () {
	int n;
	scanf ("%d", &n);
	vector < doll > dolls (n);
	for (doll & d : dolls) scanf ("%d %d", & (d.width), & (d.height));
	sort (dolls.begin(), dolls.end());
	vector < doll > rest;
	rest.push_back (dolls[0]);
	for (int i = 1; i < n; i++) {
		doll d = dolls[i];
		int l = 0, r = (int) rest.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (rest[mid].height > d.height) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (l == rest.size()) {
			rest.push_back (d);
		} else {
			rest[l] = d;
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
