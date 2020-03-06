#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void dfs (vector < vector < int > > & g, vector < bool > & visited, int u) {
	visited[u] = true;
	for (int v = 0; v < g[u].size(); v++) {
		if (g[u][v]) {
			if (!visited[v]) dfs (g, visited, v);
		}
	}
}

void solve () {
	int n;
	scanf ("%d", &n);
	string s;
	vector < vector < int > > g (26, vector < int > (26));
	for (int i = 0; i < n; i++) {
		cin >> s;
		g[s[0] - 'a'][s.back() - 'a']++;
	}
	// Check for Eulerian path in the graph
	n = 26;
	bool bad = false;
	vector < int > indegree (n), outdegree (n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			indegree[j] += g[i][j];
			outdegree[i] += g[i][j];
		}
	}
	// Outdegree[v1] - indegree[v1] = 1
	// indegree[v2] - outdegree[v2] = 1
	int v1 = -1, v2 = -1;
	for (int i = 0; i < n; i++) {
		int diff = outdegree[i] - indegree[i];
		if (diff == 1) {
			if (v1 == -1) v1 = i;
			else {
				bad = true;
				break;
			}
		} else if (diff > 1) {
			bad = true;
			break;
		}
	}
	for (int i = 0; bad == false && i < n; i++) {
		int diff = indegree[i] - outdegree[i];
		if (diff == 1) {
			if (v2 == -1) v2 = i;
			else {
				bad = true;
				break;
			}
		} else if (diff > 1) {
			bad = true;
			break;
		}
	}
	if (bad) {
		printf ("The door cannot be opened.\n");
		return;
	}
	
	// Add edge from v2 to v1
	if (v1 != -1 && v2 != -1) {
		g[v2][v1]++;
		indegree[v1]++;
		outdegree[v2]++;
	}
	
	/**
	 * Check if graph has an eulerian cycle
	 * 1) All vertices with nonzero belong to a single strongly connected component.
	 * 2) In degree is equal to the out degree for every vertex
	 */
	int first = 0;
	while (first < n && outdegree[first] == 0) first++;
	if (first == n) {
		printf ("Ordering is possible.\n");
		return;
	}
		
	vector < bool > visited (n, false);
	
	dfs (g, visited, first);
	
	for (int i = 0; i < n; i++) {
		if (outdegree[i] > 0 && !visited[i]) {
			bad = true;
			break;
		}
	}
	
	if (bad) {
		printf ("The door cannot be opened.\n");
		return;
	}
	
	visited.assign (n, false);
	
	vector < vector < int > > gr (n, vector < int > (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			gr[i][j] = g[j][i];
		}
	}
	
	dfs (gr, visited, first);
	
	for (int i = 0; i < n; i++) {
		if (indegree[i] > 0 && !visited[i]) {
			bad = true;
			break;
		}
	}
	
	if (bad) {
		printf ("The door cannot be opened.\n");
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (indegree[i] != outdegree[i]) {
			bad = true;
			break;
		}
	}
	
	if (bad) {
		printf ("The door cannot be opened.\n");
	} else {
		printf ("Ordering is possible.\n");
	}
}
	

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
