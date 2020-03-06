#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mod = 1e9 + 7;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

void max_self (int & a, int b) {
	if (a < b) a = b;
}

bool dfs (vector < vector < int > > & g, int u, int p, vector < bool > & visited) {
	visited[u] = true;
	for (int v : g[u]) {
		if (v == p) continue;
		if (visited[v]) return false;
		if (!dfs (g, v, u, visited)) return false;
	}
	return true;
}

void solve() {
	int n, m, a, b;
	scanf ("%d %d", &n, &m);
	vector < vector < int > > g (n);
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &a, &b);
		a--, b--;
		g[a].push_back (b);
		g[b].push_back (a);
	}
	if (n != 0 && m != n - 1) {
		printf ("NO\n");
		return;
	}
	vector < bool > visited (n, false);
	bool ans = dfs (g, 0, -1, visited);
	if (ans) {
		printf ("YES\n");
	} else {
		printf ("NO\n");
	}
}

int main() {
	int t;
	//scanf ("%d", &t);
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
