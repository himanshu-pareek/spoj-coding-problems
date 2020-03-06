#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
	int T, n, m, u, v;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf ("%d %d", &n, &m);
		vector < vector < int > > g (n), gr(n);
		for (int i = 0; i < m; i++) {
			scanf ("%d %d", &u, &v);
			g[u].push_back (v);
			gr[v].push_back (u);
		}
		vector < int > outdegree (n);
		for (int i = 0; i < n; i++) {
			outdegree[i] = g[i].size();
		}
		vector < bool > removed (n, false);
		int level = 0, completed = 0;
		printf ("Scenario #%d:\n", t);
		while (completed < n) {
			// find all the vertices with outdegree 0
			vector < int > vertices;
			for (int i = 0; i < n; i++) {
				if (!removed[i] && outdegree[i] == 0) {
					vertices.push_back (i);
					completed++;
				}
			}
			// all the vertices in [vertices] have rank = level + 1
			for (int vertex : vertices) {
				printf ("%d %d\n", level + 1, vertex);
				// Remove indegree of all the neighbors
				for (int v : gr[vertex]) {
					outdegree[v]--;
				}
				removed[vertex] = true;
			}
			level++;
		}		
	}
	return 0;
}
	
