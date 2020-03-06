#include <bits/stdc++.h>
using namespace std;

vector < int > order, id;
vector < bool > visited;
vector < vector < int > > g, gr;
vector < set < int > > G;

void dfs1 (int u) {
	visited[u] = true;
	for (int v : g[u]) {
		if (!visited[v]) {
			dfs1 (v);
		}
	}
	order.push_back (u);
}

void dfs2 (int u, int c) {
	visited[u] = true;
	id[u] = c;
	for (int v : gr[u]) {
		if (!visited[v]) {
			dfs2 (v, c);
		}
	}
}

void dfs3 (int u, vector < int > & cnt) {
	visited[u] = true;
	int c = 0;
	for (int v : G[u]) {
		if (!visited[v]) {
			dfs3 (v, cnt);
		}
		c += cnt[v];
	}
	cnt[u] += c;
}

void solve() {
	int n, m, u, v;
	scanf ("%d %d", &n, &m);
	g.resize (n); gr.resize (n);
	for (int i = 0; i < n; i++) {
		g[i].clear(); gr[i].clear();
	}
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &u, &v);
		u--, v--;
		gr[u].push_back (v);
		g[v].push_back (u);
	}
	visited.assign (n, false);
	order.resize (0);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs1 (i);
		}
	}
	reverse (order.begin(), order.end());
	id.assign (n, -1);
	int N = 0;
	visited.assign (n, false);
	for (int i = 0; i < n; i++) {
		if (!visited[order[i]]) {
			dfs2 (order[i], N++);
		}
	}
	G.resize (N);
	for (int i = 0; i < N; i++) G[i].clear();
	vector < int > count (N);
	for (int i = 0; i < n; i++) {
		for (int j : g[i]) {
			if (id[i] != id[j]) {
				G[id[i]].insert (id[j]);
			}
		}
		count[id[i]]++;
	}
	visited.assign (N, false);
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs3 (i, count);
		}
	}
	int maxi = 0;
	for (int i = 0; i < N; i++) {
		maxi = max (maxi, count[i]);
	}
	for (int i = 0; i < n; i++) {
		if (count[id[i]] == maxi) {
			printf ("%d ", i + 1);
		}
	}
	printf ("\n");
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
