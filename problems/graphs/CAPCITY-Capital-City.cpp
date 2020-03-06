#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mx = 1e5 + 5;
vector < vector < int > > g, gr;
vector < bool > visited;
vector < int > order, id;

void dfs1 (int v) {
	visited[v] = true;
	for (int u : g[v]) {
		if (!visited[u]) {
			dfs1 (u);
		}
	}
	order.push_back (v);
}

void dfs2 (int v, int c) {
	visited[v] = true;
	id[v] = c;
	for (int u : gr[v]) {
		if (!visited[u]) {
			dfs2 (u, c);
		}
	}
}
	

int main() {
	ios_base::sync_with_stdio (false);
	int n, m, u, v;
	cin >> n >> m;
	g.resize (n); gr.resize (n);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--, v--;
		g[u].push_back (v);
		gr[v].push_back (u);
	}
	visited.assign (n, false);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs1 (i);
		}
	}
	visited.assign (n, false);
	id.assign (n, 0);
	reverse (order.begin(), order.end());
	int c = 0;
	for (int i = 0; i < n; i++) {
		int v = order[i];
		if (!visited[v]) {
			dfs2 (v, c++);
		}
	}
	vector < int > out_degree (c, 0);
	for (int u = 0; u < n; u++) {
		for (int v : g[u]) {
			if (id[u] != id[v]) {
				out_degree[id[u]] = 1;
			}
		}
	}
	int comp = -1, cnt = 0;
	for (int i = 0; i < c; i++) {
		if (out_degree[i] == 0) {
			comp = i;
			cnt++;
		}
	}
	if (cnt > 1) {
		cout << 0 << endl;
		return 0;
	}
	int sz = 0;
	vector < int > candidates;
	for (int i = 0; i < n; i++) {
		if (id[i] == comp) candidates.push_back (i);
	}
	cout << candidates.size() << endl;
	for (int candidate : candidates) {
		cout << candidate + 1 << " ";
	}
	cout << endl;
	return 0;
}
	
