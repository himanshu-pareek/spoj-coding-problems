#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const ll inf = 1e18 + 5;

// Disjoint set union data structure
int find (vector < int > & parent, int u) {
	if (u != parent[u]) parent[u] = find (parent, parent[u]);
	return parent[u];
}

void merge (vector < int > & parent, vector < int > & rank, int u, int v) {
	int pu = find (parent, u);
	int pv = find (parent, v);
	if (pu == pv) return;
	if (rank[pu] >= rank[pv]) parent[pv] = pu;
	else parent[pu] = pv;
	if (rank[pu] == rank[pv]) rank[pu]++;
}

struct edge {
	int u, v, w;
	bool operator < (const edge & e) {
		return w < e.w;
	}
};

void addEdge (vector < vector < pii > > & g, int u, int v, int w) {
	g[u].push_back (make_pair (v, w));
	g[v].push_back (make_pair (u, w));
}

ll dfs (vector < vector < int > > & children, vector < ll > & d, int u) {
	if (children[u].empty()) {
		return d[u];
	}
	ll ans = 0;
	for (int v : children[u]) {
		ans += dfs (children, d, v);
	}
	return ans;
}

void solve() {
	int n, m, u, v, w;
	scanf ("%d %d", &n, &m);
	vector < vector < pii > > g (n);
	vector < edge > edges;
	for (int i = 0; i < m; i++) {
		scanf ("%d %d %d", &u, &v, &w);
		addEdge (g, u, v, w);
		edges.push_back ({u, v, w});
	}
	// Construct Shortest path tree from source 0
	int s = 0;
	priority_queue < pair < int, pii > > pq;
	pq.push (make_pair (0, make_pair (0, 0)));
	vector < ll > d (n, inf);
	vector < bool > visited (n);
	vector < int > lastAdded (n);
	vector < int > parent (n);
	d[s] = 0;
	visited[s] = true;
	lastAdded[s] = 0;
	parent[0] = 0;
	while (!pq.empty()) {
		pair < ll, pii > dmv = pq.top(); pq.pop();
		int u = dmv.second.second;
		int la = -dmv.second.first;
		for (pii p : g[u]) {
			int v = p.first, w = p.second;
			if (d[v] > d[u] + w || (d[v] == d[u] + w && w < lastAdded[v])) {
				//visited[v] = true;
				parent[v] = u;
				lastAdded[v] = w;
				d[v] = d[u] + w;
				pq.push (make_pair (-d[v], make_pair (-lastAdded[v], v)));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (d[i] >= inf) {
			printf ("NO\n");
			return;
		}
	}
	vector < vector < int > > children (n);
	for (int i = 1; i < n; i++) {
		children[parent[i]].push_back (i);
	}
	ll sptTreeDist = dfs (children, d, 0);
	
	// Construct MST
	sort (edges.begin(), edges.end());
	vector < int > rank (n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 1;
	}
	ll mstCost = 0;
	for (edge e : edges) {
		int u = e.u, v = e.v;
		int pu = find (parent, u);
		int pv = find (parent, v);
		if (pu != pv) {
			mstCost += e.w;
			merge (parent, rank, u, v);
		}
	}
	if (sptTreeDist == mstCost) {
		printf ("YES\n");
	} else {
		printf ("NO\n");
	}
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

