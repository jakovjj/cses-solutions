#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
const ll inf = 1e18;
 
ll n, lpy;
struct point {
	ll x;
	ll y;
} p, lp;
 
vector<point> temp, v;
set<pll> res;
deque<point> st;
 
bool ccw(point x, point y) {
	ll f = lp.x*x.y-x.x*lp.y+x.x*y.y-y.x*x.y+y.x*lp.y-lp.x*y.y;
	//cout << x.x << "," << x.y << " " << y.x << "," << y.y << " -> " << f << "\n";
	
	if (f > 0) return 1;
	else if (f < 0) return 0;
	else {
		return (abs(x.x-lp.x)*abs(x.x-lp.x)+abs(x.y-lp.y)*abs(x.y-lp.y) < abs(y.x-lp.x)*abs(y.x-lp.x)+abs(y.y-lp.y)*abs(y.y-lp.y));
	}
}

bool ccw2(point x, point y) {
	ll f = lp.x*x.y-x.x*lp.y+x.x*y.y-y.x*x.y+y.x*lp.y-lp.x*y.y;
	//cout << x.x << "," << x.y << " " << y.x << "," << y.y << " -> " << f << "\n";
	
	if (f > 0) return 1;
	else if (f < 0) return 0;
	else {
		return (abs(x.x-lp.x)*abs(x.x-lp.x)+abs(x.y-lp.y)*abs(x.y-lp.y) > abs(y.x-lp.x)*abs(y.x-lp.x)+abs(y.y-lp.y)*abs(y.y-lp.y));
	}
}
 
bool ch(point x, point y, point z) {
	ll f = z.x*x.y-x.x*z.y+x.x*y.y-y.x*x.y+y.x*z.y-z.x*y.y;
	//cout << x.x << "," << x.y << " " << y.x << "," << y.y << " -> " << f << "\n";
	
	if (f > 0) return 1;
	else return 0;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n; 
  
  lpy = inf;
  for (int i = 1; i <= n; i++) {
  	cin >> p.x >> p.y;
  	if (p.y < lpy) {lp = p; lpy = lp.y;} //finding lowest point
  	temp.push_back(p);
  }
  for (auto i : temp) if (i.x != lp.x || i.y != lp.y) v.push_back(i);
  
  //cout << "lowest point is " << lp.x << "," << lp.y << "\n";
  sort(v.begin(), v.end(), ccw);
  //for (auto i : v) cout << i.x << " " << i.y << "\n";
  
  st.push_front(lp);
  for (auto i : v) {  	
  	while (st.size() > 1 && ch(i, st[0], st[1])) {
  		//cout << "popping " << st[0].x << "," << st[0].y << "\n";
  		st.pop_front();
	}
  	
  	st.push_front(i);
  }
  
  while (!st.empty()) {
  	res.insert({st.front().x, st.front().y});
  	st.pop_front();
  }
  
  sort(v.begin(), v.end(), ccw2);
  
  st.push_front(lp);
  for (auto i : v) {  	
  	while (st.size() > 1 && ch(i, st[0], st[1])) {
  		//cout << "popping " << st[0].x << "," << st[0].y << "\n";
  		st.pop_front();
	}
  	
  	st.push_front(i);
  }
  
  while (!st.empty()) {
  	res.insert({st.front().x, st.front().y});
  	st.pop_front();
  }
  
  cout << res.size() << "\n";
  for (auto i : res) cout << i.first << " " << i.second << "\n";
 
  return 0;
}

