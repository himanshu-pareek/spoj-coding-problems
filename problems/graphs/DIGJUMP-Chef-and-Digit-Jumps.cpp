#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve() {
	string s;
	cin >> s;
	const int n = (int) s.size();
	vector < int > dist (n, -1);
	queue < int > q;
	vector < vector < int > > g (10);
	for (int i = 0; i < n; i++) {
		g[s[i] - '0'].push_back (i);
	}
	q.push (0);
	dist[0] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == n - 1) break;
		for (int v : g[s[u] - '0']) {
			if (dist[v] == -1) {
				q.push (v);
				dist[v] = dist[u] + 1;
			}
		}
		g[s[u] - '0'].clear();
		if (u > 0 && dist[u - 1] == -1) {
			q.push (u - 1);
			dist[u - 1] = dist[u] + 1;
		}
		if (u < n - 1 && dist[u + 1] == -1) {
			q.push (u + 1);
			dist[u + 1] = dist[u] + 1;
		}
	}
	printf ("%d\n", dist[n - 1]);
}

int main() {
	int t;
	t = 1;
	//scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

