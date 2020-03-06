#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void max_self (int & a, int b) {
	if (a < b) a = b;
}

void dfs1 (vector < vector < int > > & g, int u, int p, vector < int > & in) {
	int h = 0;
	for (int v : g[u]) {
		if (v != p) {
			dfs1 (g, v, u, in);
			max_self (h, 1 + in[v]);
		}
	}
	in[u] = h;
}

int dfs2 (vector < vector < int > > & g, int u, int p, vector < int > & in, vector < int > & out) {
	int mx = -1, maxInd = -1;
	int secmax = -1, secmaxInd = -1;
	for (int v : g[u]) {
		if (v != p) {
			if (in[v] >= mx) {
				secmax = mx, secmaxInd = maxInd;
				mx = in[v], maxInd = v;
			} else if (in[v] > secmax) {
				secmax = in[v], secmaxInd = v;
			}
		}
	}
	int ans = 0;
	for (int v : g[u]) {
		if (v != p) {
			int val = mx;
			if (v == maxInd) {
				val = secmax;
			}
			out[v] = max (1 + out[u], 2 + val);
			max_self (ans, in[v] + out[v]);
			max_self (ans, dfs2 (g, v, u, in, out));
		}
	}
	return ans;
}

void solve() {
	int n, a, b;
	scanf ("%d", &n);
	vector < vector < int > > g (n);
	for (int i = 1; i < n; i++) {
		scanf ("%d %d", &a, &b);
		a--, b--;
		g[a].push_back (b); g[b].push_back (a);
	}
	vector < int > in (n), out (n);
	dfs1 (g, 0, -1, in);
	out[0] = 0;
	int ans = dfs2 (g, 0, -1, in, out);
	printf ("%d\n", ans);
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
