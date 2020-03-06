#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mx = 1e5 + 10;
const int mod = 1e9;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int mul (int a, int b) {
	return (int) (((ll) a * b) % mod);
}

int power (int a, int k) {
	int answer = 1;
	while (k > 0) {
		if (k & 1) answer = mul (answer, a);
		a = mul (a, a);
		k >>= 1;
	}
	return answer;
}

int inverse (int a) {
	return power (a, mod - 2);
}

struct edge {
	int u, v, w;
	bool operator < (const edge & e) const {
		return w > e.w;
	}
};

vector < int > p (mx), r (mx), s(mx);

void init_set (int n) {
	for (int i = 0; i < n;i++){
		p[i] = i; r[i] = 1; s[i] = 1;
	}
}

int find (int u) {
	if (u != p[u]) p[u] = find (p[u]);
	return p[u];
}

int merge (int u, int v) {
	int pu = find (u);
	int pv = find (v);
	if (pu != pv) {
		if (r[pu] < r[pv]) {
			swap (pu, pv);
		}
		if (r[pu] == r[pv]) r[pu]++;
		p[pv] = pu;
		s[pu] += s[pv];
	}
	ll x = (ll) s[pu] * (s[pu] - 1);
	x >>= 1;
	return x % mod;
}

int main() {
	ios::sync_with_stdio (false);
	int n, m, u, v, w;
	cin >> n >> m;
	vector < edge > edges (m);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		u--; v--;
		edges[i] = {u, v, w};
	}
	init_set(n);
	sort (edges.begin(), edges.end());
	int answer = 0;
	for (edge e : edges) {
		int u = e.u, v = e.v, w = e.w;
		int x = merge (u, v);
		x = mul (x, w);
		add_self (answer, x);
	}
	cout << answer << endl;
	return 0;
}

