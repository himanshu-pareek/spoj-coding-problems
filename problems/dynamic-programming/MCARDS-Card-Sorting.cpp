#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

vector < vector < int > > cards;
int c, v;
int minCost;

void printArr(int a[],int n) 
{ 
    for (int i=0; i<n; i++) 
        cout << a[i] << " "; 
    printf("\n"); 
}

void max_self (int & a, int b) {
	if (b > a) a = b;
}

int lis (vector < int > & a) {
	vector < int > dp (a.size(), 1);
	int answer = 0;
	for (int i = 0; i < (int) a.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				max_self (dp[i], dp[j] + 1);
			}
		}
		max_self (answer, dp[i]);
	}
	return answer;
}
	

// Generating permutation using Heap Algorithm 
void heapPermutation(int a[], int size, int n) 
{ 
    // if size becomes 1 then prints the obtained 
    // permutation 
    if (size == 1) 
    { 
		// printArr (a, n);
        // compute cost
        // a[i] - color in ith row
        vector < int > arr;
        int cost = 0;
        for (int i = 0; i < n; i++) {
			int color = a[i];
			for (int value = 0; value < v; value++) {
				arr.push_back (cards[color][value]);
			}
		}
		cost = c * v - lis (arr);
		// printf ("%d\n", cost);
		minCost = min (minCost, cost);
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heapPermutation(a,size-1,n); 
  
        // if size is odd, swap first and last 
        // element 
        if (size%2==1) 
            swap(a[0], a[size-1]); 
  
        // If size is even, swap ith and last 
        // element 
        else
            swap(a[i], a[size-1]); 
    } 
}

int main() {
	// int c, n;
	int x, y;
	scanf ("%d %d", & c, & v);
	cards.resize (c, vector < int > (v));
	for (int i = 0; i < c * v; i++) {
		scanf ("%d %d", &x, &y);
		x--; y--;
		cards[x][y] = i;
	}
	minCost = c * v;
	int a[] = {0, 1, 2, 3};
	heapPermutation (a, c, c);
	printf ("%d\n", minCost);
	return 0;
}
	
