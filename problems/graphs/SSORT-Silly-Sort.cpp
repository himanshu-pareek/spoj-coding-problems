#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
    int N;
    int t = 1;
    while (scanf ("%d", &N) && N) {
        vector < int > A(N);
        for (int & x : A) scanf ("%d", & x);
        vector < int > B = A;
        sort (B.begin(), B.end());
        unordered_map < int, int > m;
        for (int i = 0; i < N; i++) {
            m[B[i]] = i;
        }
        int res = 0;
        vector < bool > visited (N, false);
        for (int i = 0; i < N; i++) {
            if (m[A[i]] == i) visited[i] = true;
            if (visited[i]) continue;
            int j = i;
            int sum = 0;
            int min_element = A[i];
            int k = 0;
            while (!visited[j]) {
                sum += A[j];
                k++;
                min_element = min (min_element, A[j]);
                visited[j] = true;
                j = m[A[j]];
            }
            sum -= min_element;
            res += sum + (k - 1) * min_element;

            // borrow smallest element
            int increase_cost = 2 * (min_element + B[0]);
            int decrease_cost = (min_element - B[0]) * (k - 1);
            if (increase_cost < decrease_cost) {
                res += increase_cost;
                res -= decrease_cost;
            }
        }
        printf ("Case %d: %d\n\n", t, res);
        t++;
    }
    return 0;
}


