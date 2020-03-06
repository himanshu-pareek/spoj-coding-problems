#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mx = 1e4 + 10;

vector < int > discover (mx), low (mx);
vector < bool > visited (mx);

void min_self (int & a, int b) {
	if (a > b) a = b;
}

int ttime = 0;
void dfs (vector < vector < int > > & g, vector < bool > & ans, int u, int p = -1) {
	visited[u] = true;
	discover[u] = low[u] = ttime++;
	int children = 0;
	for (int v : g[u]) {
		if (v == p) continue;
		if (visited[v]) {
			min_self (low[u], discover[v]);
		} else {
			dfs (g, ans, v, u);
			min_self (low[u], low[v]);
			children++;
			if (low[v] >= discover[u] && p != -1) {
				ans[u] = true;
			}
		}
	}
	if (children > 1 && p == -1) {
		ans[u] = true;
	}
}

int main() {
	int m, n, u, v;
	scanf ("%d %d", &n, &m);
	while (n > 0) {
		vector < vector < int > > g (n);
		while (m--) {
			scanf ("%d %d", &u, &v);
			u--, v--;
			g[u].push_back (v);
			g[v].push_back (u);
		}
		vector < bool > ans (n);
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				dfs (g, ans, i);
			}
		}
		int sum = 0;
		for (bool b : ans) sum += b;
		printf ("%d\n", sum);
		//////////////////////////
		scanf ("%d %d", &n, &m);
	}
	return 0;
}
