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

void merge (vector < int > & parent, vector < int > & rank, int pu, int pv) {
	if (rank[pu] < rank[pv]) {
		swap (pu, pv);
	}
	if (rank[pu] == rank[pv]) rank[pu]++;
	parent[pv] = pu;
}

void solve() {
	int p, n, m, a, b, c;
	cin >> p >> n >> m;
	
	vector < edge > edges;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges.push_back ({a - 1, b - 1, c});
	}
	
	vector < int > parent (n);
	vector < int > rank (n);
	
	for (int i = 0; i < n; i++) {
		parent[i] = i; rank[i] = 1;
	}
	
	sort (edges.begin(), edges.end());
	
	long cost = 0;
	for (edge e : edges) {
		int u = e.u, v = e.v, w = e.w;
		int pu = find (parent, u);
		int pv = find (parent, v);
		if (pu != pv) {
			merge (parent, rank, pu, pv);
			cost += w;
		}
	}
	
	cout << (cost * p) << endl;
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

