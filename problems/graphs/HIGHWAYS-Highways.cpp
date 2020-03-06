#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int inf = 1e9 + 10;

void solve() {
	int n, m, src, target, u, v, w;
	cin >> n >> m >> src >> target;
	src--; target--;
	vector < vector < pair < int , int > > > g (n);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		u--, v--;
		g[u].push_back ({v, w});
		g[v].push_back ({u, w});
	}
	
	vector < int > d (n, inf);
	set < pair < int, int > > s;
	d[src] = 0;
	s.insert (make_pair (0, src));
	while (!s.empty()) {
		auto it = s.begin(); pair < int, int > p = *it; s.erase (it);
		int dist = p.first, u = p.second;
		for (pair < int, int > vw : g[u]) {
			int v = vw.first, w = vw.second;
			if (d[v] > d[u] + w) {
				if (s.count ({d[v], v})) {
					s.erase ({d[v], v});
				}
				d[v] = d[u] + w;
				s.insert ({d[v], v});
			}
		}
	}
	
	if (d[target] >= inf) {
		cout << "NONE" << endl;
	} else {
		cout << d[target] << endl;
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

