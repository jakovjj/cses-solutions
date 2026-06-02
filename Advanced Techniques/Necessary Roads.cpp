#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll n, m, u, v, low[200003], st[200003], t;
bool visited[200003];
vector<ll> adj[200003];
set<pll> ap;

void dfs(ll node, ll parent) {
	visited[node] = 1;
	st[node] = ++t;
	low[node] = st[node];
	
	for (auto i : adj[node]) {
		if (i == parent) continue;
		
		if (visited[i]) low[node] = min(low[node], st[i]);
		else {
			dfs(i, node);
			low[node] = min(low[node], low[i]);
			if (low[i] > st[node]) ap.insert({node, i});
		}
	}

}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
  	cin >> u >> v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }
  
  t = 0;
  
  dfs(1, 0);
  
  cout << ap.size() << "\n";
  for (auto i : ap) cout << i.first << " " << i.second << "\n";

  return 0;
}


