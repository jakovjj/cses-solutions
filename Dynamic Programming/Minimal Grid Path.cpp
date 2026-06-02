#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;
mt19937 rng(time(0));
 
int n, dirx[3003][3003], diry[3003][3003], dist[3003][3003], md;
char a[3003][3003], b;
vector<char> res;
queue<pair<char, pll>> q, v;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n;
  REP(i, n) REP(j, n) cin >> a[i][j];
  q.push({a[1][1], {1, 1}});
  
  dirx[1][1] = 1; diry[1][1] = 1;
  while (!q.empty()) {
  	
  	while (!q.empty()) {
  		while (!v.empty() && q.front().first < v.front().first) v.pop();
		if (v.empty() || q.front().first <= v.front().first) v.push(q.front());
		q.pop();	
	}
  	
  	while (dirx[n][n] == 0 && !v.empty()) {
	  	pair<char, pll> t = v.front(); v.pop();
	  	int x = t.second.first; int y = t.second.second;
	  	
	  	dist[x][y] = dist[dirx[x][y]][diry[x][y]]+1;
	  	if (dist[x][y] > md) {b = a[x][y]; md = dist[x][y];}
	  	
	  	if (dist[x][y] < md || a[x][y] > b) continue;
	  	md = max(md, dist[x][y]);
	  	b = min(b, a[x][y]);
	  	
	  	if (x+1 <= n && dirx[x+1][y] == 0) {
	  		dirx[x+1][y] = x; diry[x+1][y] = y;
	  		q.push({a[x+1][y], {x+1, y}});
		}
		if (y+1 <= n && dirx[x][y+1] == 0) {
	  		dirx[x][y+1] = x; diry[x][y+1] = y;
	  		q.push({a[x][y+1], {x, y+1}});
		}
  	}
  }
  
  int x = n; int y = n;
  while (x != 1 || y != 1) {
  	res.push_back(a[x][y]);
  	int tx = x;
  	x = dirx[x][y];
  	y = diry[tx][y];
  }
  
  res.push_back(a[x][y]);
  reverse(res.begin(), res.end());
  for (auto i : res) cout << i;
 
  return 0;
}
