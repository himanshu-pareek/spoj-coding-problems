#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

void add_self (int & a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int mul (int a, int b) {
    return (int) (((ll) a * b) % mod);
}

void solve() {
    int a, b, c, n;
    scanf ("%d %d %d %d", &a, &b, &c, &n);
    priority_queue < int, vector < int >, greater < int > > minpq;
    priority_queue < int > maxpq;
    minpq.push (1);
    ll answer = 1L;
    for (int i = 2; i <= n; i++) {
        int m = minpq.top();
        if (minpq.size() == maxpq.size()) {
            m = maxpq.top();
        }
        int f = mul (a, m);
        add_self (f, mul (b, i));
        add_self (f, c);

        // Add f to answer
        answer += f;

        // Add f to appropriate priority queue
        if (minpq.size() <= maxpq.size()) {
            // Insert into minpq
            if (maxpq.top() > f) {
                int f_dash = maxpq.top(); maxpq.pop();
                maxpq.push (f);
                f = f_dash;
            }
            minpq.push (f);
        } else {
            // Insert into maxpq
            if (minpq.top() < f) {
                int f_dash = minpq.top(); minpq.pop();
                minpq.push (f);
                f = f_dash;
            }
            maxpq.push (f);
        }
    }
    printf ("%lld\n", answer);
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
