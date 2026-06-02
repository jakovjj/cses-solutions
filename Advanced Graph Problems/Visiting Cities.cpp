#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= (b); i++)
const ll mod = 1e9+7; const ll inf = 1e18;
 
ll n, m, u, v, w, d[200003];
vector<ll> res;
priority_queue<pair<pll, pll>, vector<pair<pll, pll>>, greater<pair<pll, pll>>> pq;
vector<pll> adj[200003], adjn[200003];
priority_queue<pll> pqn;
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n >> m;
  
  REP(i, m) {
  	cin >> u >> v >> w;
  	adj[u].push_back({w, v});
  }
  
  memset(d, 0x7f, sizeof(d));
  
  pq.push({{0, 1}, {0, 0}});
  while (!pq.empty()) {
  	pair<pll, pll> x = pq.top();
  	pq.pop();
  	
  	if (d[x.F.S] < x.F.F) continue;
  	if (x.S.S) {
  		adjn[x.F.S].push_back({x.S.F, x.S.S});
  		//cout << "adding edge " << x.F.S << " to " << x.S.S << " of cost " << x.S.F << "\n";
	}
	
	if (d[x.F.S] == x.F.F) continue;
	d[x.F.S] = x.F.F;
	for (auto i : adj[x.F.S]) pq.push({{i.F+d[x.F.S], i.S}, {i.F, x.F.S}});
  }
  
  //memset(d, 0x7f, sizeof(d));
  //pq.push({{0, n}, {0, 0}});
  
  bool vis[200003];
  
  pqn.push({d[n], n});
  while (!pqn.empty()) {
  	pll x = pqn.top();
  	if (pqn.size() == 1) res.push_back(x.S);
  	
  	//cout << "at " << x.S << " when pq is size of " << pqn.size() << "\n";
  	pqn.pop();
  	
	for (auto i : adjn[x.S]) {
		//cout << "pushing " << i.S << "at " << d[i.S] << "\n";
		if (!vis[i.S]) pqn.push({d[i.S], i.S});
		vis[i.S] = 1;
	}
  }
  
  sort(res.begin(), res.end());
  cout << res.size() << "\n"; for (auto i : res) cout << i << " ";
 
  return 0;
}
