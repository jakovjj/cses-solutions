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

ll n, a[1003][1003];
bool vis[1003][1003];
queue<pair<ll, pll>> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  q.push({0, {1, 1}});
  
  while (!q.empty()) {
  	pair<ll, pll> p = q.front();
  	q.pop();
  	
  	int x = p.second.first; int y = p.second.second;
  	if (x > n || x < 1 || y > n || y < 1 || vis[x][y]) continue;
  	
  	a[x][y] = p.first;
  	vis[x][y] = 1;
  	
  	q.push({p.first+1, {x+2, y+1}});
  	q.push({p.first+1, {x+2, y-1}});
  	q.push({p.first+1, {x-2, y+1}});
  	q.push({p.first+1, {x-2, y-1}});
  	q.push({p.first+1, {x+1, y+2}});
  	q.push({p.first+1, {x+1, y-2}});
  	q.push({p.first+1, {x-1, y+2}});
  	q.push({p.first+1, {x-1, y-2}});
  }
  
  REP(i, n) {
  	REP(j, n) cout << a[i][j] << " ";
  	cout << "\n";
  }

  return 0;
}


