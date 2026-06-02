#include <bits/stdc++.h>
using namespace std;
 
int n, m, a, b, cyc;
bool inc, visited[100003];
vector<int> adj[100003], ans, route;
 
void dfs(int node, int parent) {
	if(cyc || visited[node]) return;
	
	visited[node] = 1; 
	route.push_back(node);
	
	for (auto u : adj[node]) {
		if (u == parent || cyc) continue;
		if(visited[u]) {cyc = u; inc = 1; break;}
		dfs(u, node);
	}
	
	if (inc) ans.push_back(route.back());
	route.pop_back();
	if (node == cyc) inc = 0; 
	return;
}
 
int main()
{  
  cin >> n >> m;
  for (int i = 0; i < m; i++) {cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);}
  for (int i = 1; i <= n; i++) if (!visited[i] && route.empty()) {inc = 0; dfs(i, 0);}
 
  if (ans.empty()) {cout << "IMPOSSIBLE";}
  else {	  
  	cout << ans.size()+1 << endl;
  	cout << cyc << " "; for (auto i : ans) cout << i << " ";
  }
  
  return 0;
}

