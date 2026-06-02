#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const ll inf = 1e18;

ll n, m, cnt;
struct point {
	ll x;
	ll y;
} p;

vector<point> polygon;

ll ccw(point x, point y, point z) {
	return x.x*y.y-y.x*x.y + y.x*z.y-z.x*y.y + z.x*x.y-x.x*z.y;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
  	cin >> p.x >> p.y;
  	polygon.push_back(p);
  }
  
  for (ll i = 1; i <= m; i++) {
  	cin >> p.x >> p.y;
  	cnt = 0;
  	
  	bool b = 0;
  	for (ll j = 0; j < n; j++) {
  		ll x = (j+1)%n; //x -> next point
  		
  		//cout << p.x << "," << p.y << " to " << polygon[j].x << "," << polygon[j].y << " to " << polygon[x].x << "," << polygon[x].y << " -> " << ccw(p, polygon[j], polygon[x]) << "\n";
  		//cout << p.x << "," << p.y << " to " << polygon[x].x << "," << polygon[x].y << " to " << polygon[j].x << "," << polygon[j].y << " -> " << ccw(p, polygon[x], polygon[j]) << "\n";
  		
  		if (polygon[j].y <= p.y && p.y < polygon[x].y && ccw(p, polygon[j], polygon[x]) > 0) {
  			//cout << "CUT 1!\n";
  			cnt++;
		  }
		if (polygon[x].y <= p.y && p.y < polygon[j].y && ccw(p, polygon[x], polygon[j]) > 0) {
			//cout << "CUT 2!\n";
			cnt++;
		}
		
		if (polygon[j].y <= p.y && p.y <= polygon[x].y && ccw(p, polygon[j], polygon[x]) == 0 && p.x <= max(polygon[x].x, polygon[j].x) && p.x >= min(polygon[x].x, polygon[j].x)) b = 1;
		if (polygon[x].y <= p.y && p.y <= polygon[j].y && ccw(p, polygon[x], polygon[j]) == 0 && p.x <= max(polygon[x].x, polygon[j].x) && p.x >= min(polygon[x].x, polygon[j].x)) b = 1;
	}
	
	//cout << p.x << "," << p.y << " -> " << cnt << "\n";
	
	if (b) cout << "BOUNDARY\n";
	else {cnt%2 ? cout << "INSIDE\n" : cout << "OUTSIDE\n";}
  }

  return 0;
}


