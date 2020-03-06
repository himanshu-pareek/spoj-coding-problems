#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
	int n, m;
	string currency, source, dest;
	double cost;
	for (int t = 1; ; t++) {
		cin >> n;
		if (n == 0) break;
		map < string, int > mp;
		for (int i = 0; i < n; i++) {
			cin >> currency;
			mp[currency] = i;
		}
		cin >> m;
		vector < vector < double > > g (n, vector < double > (n, 0.0));
		for (int i = 0; i < m; i++) {
			cin >> source >> cost >> dest;
			int u = mp[source];
			int v = mp[dest];
			g[u][v] = cost;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					g[i][j] = max (g[i][j], g[i][k] * g[k][j]);
				}
			}
		}
		bool possible = false;
		for (int i = 0; i < n; i++) {
			if (g[i][i] > 1.0) {
				possible = true;
				break;
			}
		}
		/**
		 * Case 1: Yes
		 * Case 2: No
		 */
		cout << "Case " << t << ": ";
		if (possible) {
			cout << "Yes";
		} else {
			cout << "No";
		}
		cout << endl;
	}
	return 0;
}
