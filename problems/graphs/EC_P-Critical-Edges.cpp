#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mx = 1005;

vector < int > discover (mx), low (mx);
vector < bool > visited (mx);

int timer = 0;
void dfs (vector < vector < int > > & g, vector < pii > & res, int u, int p = -1) {
	visited[u] = true;
	discover[u] = low[u] = timer++;
	for (int v : g[u]) {
		if (v == p) continue;
		if (visited[v]) {
			low[u] = min (low[u], discover[v]);
		} else {
			dfs (g, res, v, u);
			low[u] = min (low[u], low[v]);
			if (discover[u] < low[v]) {
				// u -> v is a bridge
				res.push_back (make_pair (min (u, v), max (u, v)));
			}
		}
	}
}

int main() {
	int nc, n, m, u, v;
	scanf ("%d", &nc);
	for (int t = 1; t <= nc; t++) {
		scanf ("%d %d", &n, &m);
		vector < vector < int > > g (n);
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			u--, v--;
			g[u].push_back (v);
			g[v].push_back (u);
		}
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}
		vector < pii > ans;
		timer = 0;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				dfs (g, ans, i);
			}
		}
		//Caso #1
		//4
		//1 2
		//2 3
		//2 4
		//4 5
		printf ("Caso #%d\n", t);
		if (ans.empty()) {
			printf ("Sin bloqueos\n");
		} else {
			printf ("%d\n", (int)ans.size());
			sort (ans.begin(), ans.end());
			for (pii p : ans) {
				printf ("%d %d\n", p.first + 1, p.second + 1);
			}
		}
	}
	return 0;
}
