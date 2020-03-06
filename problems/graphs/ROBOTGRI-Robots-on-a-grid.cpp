#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const ll mod = (1LL << 31) - 1;

void add_self (ll & a, ll b) {
    // cout << "mod = " << mod << endl;
    // long c = a + b;
    // if (c >= mod) c -= mod;
    // a = c;
    // a += b;
    // if (a >= mod) a -= mod;
    a = (a + b) % mod;
}


vector < pair < int, int > > toAdd = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool dfs (vector < string > & grid, vector < vector < bool > > & visited, int row, int col) {
    visited[row][col] = true;
    if (row + 1 == grid.size() && col + 1 == grid.size()) return true;
    for (pair < int, int > &p : toAdd) {
        int x = row + p.first;
        int y = col + p.second;
        if (x >= 0 && y >= 0 && x < grid.size() && y < grid.size() && grid[x][y] == '.' && !visited[x][y]) {
            if (dfs (grid, visited, x, y)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    scanf ("%d", &n);
    vector < string > grid (n);
    for (string & s : grid) {
        cin >> s;
    }
    vector < vector < ll > > paths (n, vector < ll > (n));
    // paths[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                paths[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0) paths[i][j] = 1;
            else if (i == 0) paths[i][j] = paths[i][j - 1];
            else if (j == 0) paths[i][j] = paths[i - 1][j];
            else {
                paths[i][j] = (paths[i - 1][j] + paths[i][j - 1]) % mod;
            }
        }
    }
    if (paths[n - 1][n - 1] > 0) {
        printf ("%lld\n", paths[n - 1][n - 1]);
        return 0;
    }
    vector < vector < bool > > visited (n, vector < bool > (n));
    bool res = dfs (grid, visited, 0, 0);
    if (res) {
        printf ("THE GAME IS A LIE\n");
    } else {
        printf ("INCONCEIVABLE\n");
    }
}


