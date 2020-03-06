#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;
using pill = pair < int, ll >;
using plli = pair < ll, int >;

const ll inf = 1e18 + 5;

template < typename T >
T getRandomBetween (T a, T b) {
	return a + rand() % (b - a + 1);
}

void solve() {
	int n, r, u, v;
	// n = getRandomBetween (5, 6);
	scanf ("%d %d", &n, &r);
	vector < ll > height (n), cost (n);
	for (ll & h : height) scanf ("%lld", & h);
	for (ll & c : cost  ) scanf ("%lld", & c);
	vector < vector < pill > > g (2 * n);
	for (int i = 0; i < r; i++) {
		scanf ("%d %d", &u, &v);
		u--; v--;
		if (height[u] <= height[v]) {
			g[2 * u].push_back ({2 * v, 0});
			g[2 * v + 1].push_back ({2 * u + 1, 0});
		}
		if (height[u] >= height[v]) {
			g[2 * v].push_back ({2 * u, 0});
			g[2 * u + 1].push_back ({2 * v + 1, 0});
		}
	}
	for (int i = 0; i < n; i++) {
		g[2 * i].push_back ({2 * i + 1, cost[i]});
		g[2 * i + 1].push_back ({2 * i, cost[i]});
	}
	priority_queue < plli > pq;
	vector < ll > dist (2 * n, inf);
	//vector < bool > visited (2 * n);
	pq.push ({0, 0});
	pq.push ({0, 1});
	dist[0] = dist[1] = cost[0];
	//visited[0] = visited[1] = false;
	while (!pq.empty()) {
		plli p = pq.top(); pq.pop();
		int u = p.second;
		if (u == 2 * (n - 1) || u == 2 * n - 1) break;
		for (pill v : g[u]) {
			if (dist[v.first] > dist[u] + v.second) {
				dist[v.first] = dist[u] + v.second;
				pq.push ({-dist[v.first], v.first});
			}
		}
	}
	ll ans = min (dist[2 * n - 2], dist[2 * n - 1]);
	// cout << max (dist[2 * n - 2], dist[2 * n - 1]) << endl;
	ans = ans >= inf ? -1 : ans;
	printf ("%lld\n", ans);
}

int main() {
	int t;
	t = 1;
	//scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

