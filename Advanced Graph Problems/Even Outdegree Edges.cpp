#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll n, m, a, b, t, vis[200003];
bool p[200003], w;
vector<ll> adj[200003];
vector<pll> e;

void dfs(ll node, ll parent) {
	vis[node] = ++t;
	
	for (auto i : adj[node]) {
		if (i == parent) continue;
		
		if (vis[i] < vis[node] && vis[i] != 0) {
			p[node] = !p[node];
			e.push_back({node, i});
			
			continue;		
		}
		
		if (vis[i] != 0) continue;
		
		dfs(i, node);
		if (!p[i]) {
			p[node] = !p[node];
			e.push_back({node, i});
			
			//cout << node << " to " << i << "\n";
		}
		else {
			p[i] = !p[i];
			e.push_back({i, node});
			//cout << i << " to " << node << "\n";
		}
	}
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
  	cin >> a >> b;
  	adj[a].push_back(b);
  	adj[b].push_back(a);
  }
  
  t = 0;
  for (int i = 1; i <= n; i++) {
  	if (!vis[i]) dfs(i, 0);
  }
  
  w = 1;
  for (int i = 1; i <= n; i++) if (p[i]) w = 0;
  
  if (!w) {cout << "IMPOSSIBLE"; return 0;}
  for (auto i : e) cout << i.first << " " << i.second << "\n";

  return 0;
}


