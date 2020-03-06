#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int mul (int a, int b) {
	return (int) (((ll) a * b) % mod);
}

void dfs (vector < vector < int > > & graph, int s, vector < int > & leader, int ld) {
	leader[s] = ld;
	for (int u : graph[s]) {
		if (leader[u] == -1) {
			dfs (graph, u, leader, ld);
		}
	}
}

void addEdge (vector < vector < int > > & g, int u, int v) {
	g[u].push_back (v);
	g[v].push_back (u);
}

void solve() {
	int n, m, i, j;
	scanf ("%d %d", &n, &m);
	vector < vector < int > > graph (2 * n);
	while (m--) {
		scanf ("%d %d", &i, &j);
		i--, j--;
		addEdge (graph, 2 * i, 2 * j + 1);
		addEdge (graph, 2 * i + 1, 2 * j);
	}
	vector < int > leader (2 * n, -1);
	for (int i = 0; i < 2 * n; i++) {
		if (leader[i] == -1) {
			dfs (graph, i, leader, i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (leader[2 * i] == leader[2 * i + 1]) {
			printf ("Suspicious bugs found!\n");
			return;
		}
	}
	printf ("No suspicious bugs found!\n");
}

int main() {
	int t;
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf ("Scenario #%d:\n", i);
		solve();
	}
	return 0;
}
