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

void dfs (vector < vector < int > > & g, int s, int t, vector < bool > & visited, stack < int > & st) {
	visited[s] = true;
	if (s != t) {
		for (int u : g[s]) {
			if (!visited[u]) {
				dfs (g, u, t, visited, st);
			}
		}
	}
	st.push (s);
}

void solve() {
	int n, m, s, t, a, b;
	scanf ("%d %d %d %d", &n, &m, &s, &t);
	s--; t--;
	vector < vector < int > > g (n);
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &a, &b);
		a--, b--;
		g[a].push_back (b);
	}
	/**
	 * want to go from s to t
	 * topological ordering
	 */
	vector < bool > visited (n, false);
	stack < int > st;
	dfs (g, s, t, visited, st);
	vector < int > ways (n);
	ways[s] = 1;
	while (!st.empty()) {
		int u = st.top(); st.pop();
		//cout << u << " -> ";
		for (int v : g[u]) {
			add_self (ways[v], ways[u]);
		}
	}
	printf ("%d\n", ways[t]);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
