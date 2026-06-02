#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

int n, m, a, b, k, indeg[100003];
map<pii, bool> visited;
vector<int> adj[100003], path;

void dfs(int node) {
	
	while (!adj[node].empty()) {
		k = adj[node].back();
		adj[node].pop_back();
		
		if (visited[{node ,k}]) continue;
		visited[{node, k}] = 1;
		dfs(k);
	}
	
	
	path.push_back(node);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  
  for (int i = 1; i <= m; i++) {
  	cin >> a >> b;
  	adj[a].push_back(b);
  	indeg[b]++;
  }
  
  for (int i = 2; i <= n-1; i++) {if (adj[i].size() != indeg[i]) {cout << "IMPOSSIBLE"; return 0;}}
  if (adj[1].size() != indeg[1]+1) {cout << "IMPOSSIBLE"; return 0;}
  if (adj[n].size()+1 != indeg[n]) {cout << "IMPOSSIBLE"; return 0;}
  
  dfs(1);
  
  if (path.size() != m+1) {cout << "IMPOSSIBLE"; return 0;}
  reverse(path.begin(), path.end());
  for (auto i : path) cout << i << " ";

  return 0;
}


