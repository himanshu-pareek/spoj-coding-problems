#include <bits/stdc++.h>
using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector < int > color, order;
vector < set < int > > g;
bool possible;

void dfs (int u) {
	color[u] = GRAY;
	for (auto it = g[u].rbegin(); it != g[u].rend(); it++) {
		int v = *it;
		if (color[v] == GRAY) {
			possible = false;
			return;
		}
		if (color[v] == WHITE) {
			dfs (v);
		}
	}
	order.push_back (u);
	color[u] = BLACK;
}

int main() {
	int n, m, u, v;
	scanf ("%d %d", &n, &m);
	g.resize (n);
	for (int i = 0; i < n; i++) {
		g[i].clear();
	}
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &u, &v);
		u--; v--;
		g[u].insert (v);
	}
	color.assign (n, WHITE);
	order.resize (0);
	possible = true;
	for (int i = n - 1; i >= 0; i--) {
		if (color[i] == WHITE) {
			dfs (i);
		}
	}
	if (possible) {
		reverse (order.begin(), order.end());
		for (int x : order) {
			printf ("%d ", x + 1);
		}
		printf ("\n");
	} else {
		printf ("Sandro fails.\n");
	}
	return 0;
}
