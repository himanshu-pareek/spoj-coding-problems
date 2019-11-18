#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int N;
	cin >> N;
	string s;
	vector < ll > a (N);
	for (int i = 0; i < N; i++) {
		cin >> s >> a[i];
	}
	sort (a.begin(), a.end());
	ll answer = 0;
	for (int i = 0; i < N; i++) {
		answer += abs (a[i] - i - 1L);
	}
	cout << answer << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
