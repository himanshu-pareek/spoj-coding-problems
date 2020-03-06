#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

struct edge {
	int u, v, w;
	bool operator < (const edge & e) const {
		return w < e.w;
	}
};

int find (vector < int > & parent, int u) {
	if (u != parent[u]) parent[u] = find (parent, parent[u]);
	return parent[u];
}

void merge (vector < int > & parent, vector < int > & rank, vector < bool > & a, int pu, int pv) {
	if (rank[pu] < rank[pv]) {
		swap (pu, pv);
	}
	if (rank[pu] == rank[pv]) rank[pu]++;
	parent[pv] = pu;
	a[pu] = a[pu] || a[pv];
}

void solve() {
	int n, m, x, u, v, w;
	cin >> n >> m;
	vector < bool > isMilkman (n);
	for (int i = 0; i < n; i++) {
		cin >> x;
		isMilkman[i] = (bool) x;
	}
	vector < edge > edges;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		u--, v--;
		edges.push_back ({u, v, w});
	}
	sort (edges.begin(), edges.end());
	ll cost = 0;
	vector < int > parent (n);
	vector < int > rank (n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 1;
	}
	for (edge e : edges) {
		int u = e.u, v = e.v, w = e.w;
		int pu = find (parent, u);
		int pv = find (parent, v);
		if (pu == pv) continue;
		if (isMilkman[pu] && isMilkman[pv]) continue;
		cost += w;
		merge (parent, rank, isMilkman, pu, pv);
	}
	int possible = true;
	for (int i = 0; i < n; i++) {
		int p = find (parent, i);
		if (!isMilkman[p]) {
			possible = false;
			break;
		}
	}
	if (possible) {
		cout << cost << endl;
	} else {
		cout << "impossible" << endl;
	}
}

int main() {
	ios::sync_with_stdio (false);
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

