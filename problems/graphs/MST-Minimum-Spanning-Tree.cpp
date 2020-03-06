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

int FIND_SET (vector < int > & parent, int i) {
	if (i != parent[i]) parent[i] = FIND_SET (parent, parent[i]);
	return parent[i];
}
	
void MERGE_SET (vector < int > & parent, vector < int > & rank, int pu, int pv) {
	if (rank[pu] >= rank[pv]) parent[pv] = pu;
	else parent[pu] = pv;
	if (rank[pu] == rank[pv]) rank[pu]++;
}

void solve() {
	int n, m, u, v, w;
	cin >> n >> m;
	vector < edge > edges (m);
	for (int i = 0; i < m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
		--edges[i].u; --edges[i].v;
	}
	vector < int > parent (n);
	vector < int > rank (n);
	
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
	
	sort (edges.begin(), edges.end());
	
	ll totalCost = 0LL;
	for (edge e : edges) {
		int u = e.u, v = e.v;
		int pu = FIND_SET (parent, u);
		int pv = FIND_SET (parent, v);
		if (pu != pv) {
			totalCost += e.w;
			MERGE_SET (parent, rank, pu, pv);
		}
	}
	cout << totalCost << endl;
}

int main() {
	ios::sync_with_stdio (false);
	int t;
	t = 1;
	//scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

