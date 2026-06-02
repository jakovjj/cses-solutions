#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

struct point{
	ll x;
	ll y;
} pa, pb, pc, pd;

ll ccw(point x, point y, point z) {
	ll res = x.x*(y.y-z.y)+y.x*(z.y-x.y)+z.x*(x.y-y.y);
	
	if (res > 0) return 1;
	else if (res < 0) return -1;
	else return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  testcases {
  	cin >> pa.x >> pa.y >> pb.x >> pb.y >> pc.x >> pc.y >> pd.x >> pd.y;
  	
  	if (ccw(pa, pb, pc) == 0 && pc.x >= min(pa.x, pb.x) && pc.x <= max(pa.x, pb.x) && pc.y >= min(pa.y, pb.y) && pc.y <= max(pa.y, pb.y)) {cout << "YES\n"; continue;}
  	if (ccw(pa, pb, pd) == 0 && pd.x >= min(pa.x, pb.x) && pd.x <= max(pa.x, pb.x) && pd.y >= min(pa.y, pb.y) && pd.y <= max(pa.y, pb.y)) {cout << "YES\n"; continue;}
  	if (ccw(pc, pd, pa) == 0 && pa.x >= min(pc.x, pd.x) && pa.x <= max(pc.x, pd.x) && pa.y >= min(pc.y, pd.y) && pa.y <= max(pc.y, pd.y)) {cout << "YES\n"; continue;}
  	if (ccw(pc, pd, pb) == 0 && pb.x >= min(pc.x, pd.x) && pb.x <= max(pc.x, pd.x) && pb.y >= min(pc.y, pd.y) && pb.y <= max(pc.y, pd.y)) {cout << "YES\n"; continue;}
  	
  	(ccw(pa, pb, pc) * ccw(pa, pb, pd) < 0LL && ccw(pc, pd, pa) * ccw(pc, pd, pb) < 0LL) ? cout << "YES\n" : cout << "NO\n";
  }

  return 0;
}


