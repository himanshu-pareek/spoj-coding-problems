#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void SET_INITIALIZE (vector < int > & parent, vector < int > & rank, vector < int > & sz, int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 1;
		sz[i] = 1;
	}
}

int SET_FIND (vector < int > & parent, int u) {
	if (u != parent[u]) parent[u] = SET_FIND (parent, parent[u]);
	return parent[u];
}

ll merge (vector < int > & parent, vector < int > & rank, vector < int > & sz, int u, int v, ll sum) {
	int pu = SET_FIND (parent, u);
	int pv = SET_FIND (parent, v);
	if (pu == pv) return sum;
	if (rank[pu] < rank[pv]) {
		swap (pu, pv);
	}
	if (rank[pu] == rank[pv]) rank[pu]++;
	sum -= (ll) sz[pu] * sz[pu];
	sum -= (ll) sz[pv] * sz[pv];
	parent[pv] = pu;
	sz[pu] += sz[pv];
	sum += (ll) sz[pu] * sz[pu];
	return sum;
}

void solve() {
	int n, q, x;
	char option;
	cin >> n;
	vector < pair < int, int > > edges (n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> edges[i].first >> edges[i].second;
		edges[i].first--; edges[i].second--;
	}
	cin >> q;
	vector < pair < int, int > > queries (q);
	vector < bool > removed (n - 1, false);
	for (int i = 0; i < q; i++) {
		cin >> option;
		x = -1;
		if (option == 'R') {
			cin >> x;
			removed[x - 1] = true;
		}
		queries[i] = make_pair (option, x - 1);
	}
	ll sumSquares = n;
	
	vector < int > parent (n);
	vector < int > rank (n);
	vector < int > sz (n);
	
	SET_INITIALIZE (parent, rank, sz, n);
	
	for (int i = 0; i < n - 1; i++) {
		if (!removed[i]) {
			sumSquares = merge (parent, rank, sz, edges[i].first, edges[i].second, sumSquares);
		}
	}
	
	//stack < ll > s;
	vector < ll > ans (q);
	for (int i = q - 1; i >= 0; i--) {
		ans[i] = (ll) n * n - sumSquares;
		if (queries[i].first == 'R') {
			int j = queries[i].second;
			sumSquares = merge (parent, rank, sz, edges[j].first, edges[j].second, sumSquares);
		}
		//if (i > 0 && queries[i - 1].first == 'Q') {
			//s.push (((ll) n * n - sumSquares) / 2);
		//}
	}
	
	//while (!s.empty()) {
		//cout << s.top() << endl;
		//s.pop();
	//}
	for (int i = 0; i < q; i++) {
		if (queries[i].first == 'Q') {
			cout << (ans[i] / 2) << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio (false);
	int t;
	t = 1;
	cin >> t;
	while (t) {
		solve();
		if (t > 1) cout << endl;
		t--;
	}
	return 0;
}

