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
	int n, v, w, m;
	string city;
	cin >> n;
	vector < edge > edges;
	for (int i = 0; i < n; i++) {
		cin >> city >> m;
		while (m--) {
			cin >> v >> w;
			edges.push_back ({i, v - 1, w});
		}
	}
	long cost = 0L;
	vector < int > parent (n);
	vector < int > rank (n);
	
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 1;
	}
	
	sort (edges.begin(), edges.end());
	
	for (edge e : edges) {
		int u = e.u, v = e.v;
		int pu = find (parent, u);
		int pv = find (parent, v);
		if (pu == pv) continue;
		cost += e.w;
		merge (parent, rank, pu, pv);
	}
	cout << cost << endl;
}

int main() {
	ios::sync_with_stdio (false);
	int t;
	t = 1;
	//scanf ("%d", &t);
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

