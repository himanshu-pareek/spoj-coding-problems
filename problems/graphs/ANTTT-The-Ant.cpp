#include <bits/stdc++.h>
using namespace std;

const int mx = 1005;

vector < int > p (mx), r (mx);

void init (int n) {
	for (int i = 0; i < n; i++) {
		p[i] = i; r[i] = 1;
	}
}

int find (int i) {
	if (i != p[i]) p[i] = find (p[i]);
	return p[i];
}

void merge (int u, int v) {
	int pu = find (u);
	int pv = find (v);
	if (r[pu] < r[pv]) {
		swap (pu, pv);
	}
	if (r[pu] == r[pv]) {
		r[pu]++;
	}
	p[pv] = pu;
}

struct Point {
	int x;
	int y;
};

bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 

int orientation(Point p, Point q, Point r) 
{  
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  
  
    return (val > 0)? 1: 2;  
} 
  
 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 

int main() {
	int t, n, m, ax, ay, bx, by, x, y;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &n, &m);
		vector < pair < Point, Point > > segments;
		for (int i = 0; i < n; i++) {
			scanf ("%d %d %d %d", &ax, &ay, &bx, &by);
			segments.push_back (make_pair ((Point){ax, ay}, (Point){bx, by}));
		}
		init (n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (doIntersect (segments[i].first, segments[i].second,
								segments[j].first, segments[j].second)) {
					merge (i, j);
				}
			}
		}
		while (m--) {
			scanf ("%d %d", &x, &y);
			x--; y--;
			if (find(x) == find (y)) {
				printf ("YES\n");
			} else {
				printf ("NO\n");
			}
		}
	}
	return 0;
}

