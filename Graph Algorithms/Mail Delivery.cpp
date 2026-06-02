#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

int n, m, p, a, b;
vector<int> path;
map<pii, bool> visited;

vector<int> adj[200003];

void dfs(int node) {
	
	while (!adj[node].empty()) {
		
		p = adj[node].back();
		
		adj[node].pop_back();
		if (visited[{node, p}] || visited[{p, node}]) continue;
		visited[{node, p}] = 1;
		dfs(p);
	}	
	
	path.push_back(node);
	return;
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
  
  for (int i = 1; i <= n; i++) if (adj[i].size()%2) {cout << "IMPOSSIBLE"; return 0;}
  
  dfs(1);
  
  if (path.size() != m+1) {cout << "IMPOSSIBLE"; return 0;}
  for (auto i : path) cout << i << " ";

  return 0;
}


