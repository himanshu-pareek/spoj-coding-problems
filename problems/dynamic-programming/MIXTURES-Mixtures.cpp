#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

template < typename T >
void printMat (vector < vector < T > > & mat) {
	for (vector < T > vec : mat) {
		for (T x : vec) {
			cout << x << " ";
		}
		cout << endl;
	}
	cout << endl;
}

const int mod = 100;

int add (int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int sub (int a, int b) {
	a -= b;
	if (a < 0) a += mod;
	return a;
}

int min_self (int & a, int b) {
	if (a > b) a = b;
}

void solve (int n) {
	//int n;
	//scanf ("%d", &n);
	vector < int > colors (n);
	for (int & x : colors) scanf ("%d", & x);
	vector < vector < int > > dp (n, vector < int > (n));
	vector < int > sum (n);
	sum[0] = colors[0];
	for (int i = 1; i < n; i++) {
		sum[i] = add (sum[i - 1], colors[i]);
	}
	for (int len = 1; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			if (len == 1) dp[i][j] = 0;
			else if (len == 2) dp[i][j] = colors[i] * colors[j];
			else {
				dp[i][j] = INT_MAX;
				for (int k = i; k < j; k++) {
					int color1 = add (sub (sum[k], sum[i]), colors[i]);
					int color2 = add (sub (sum[j], sum[k + 1]), colors[k + 1]);
					min_self (dp[i][j], dp[i][k] + dp[k + 1][j] + color1 * color2);
				}
			}
		}
	}
	//printMat (dp);
	printf ("%d\n", dp[0][n - 1]);
}

int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		solve (n);
	}
	return 0;
}
