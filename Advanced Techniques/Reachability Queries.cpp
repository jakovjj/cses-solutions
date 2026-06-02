#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;

int n, m, q, id[50003], llv[50003], scc[50003], c, a, b;
bool onstack[50003], visited[50003];
vector<int> adj[50003];
vector<int> sccadj[50003];
bitset<50003> sccreach[50003];
stack<int> s;

void dfs(int node) {
	if (visited[node]) return;
	
	visited[node] = 1;
	onstack[node] = 1;
	id[node] = ++c;
	scc[node] = node;
	llv[node] = id[node];
	s.push(node);
	
	for (auto i : adj[node]) {dfs(i); if (onstack[i]) llv[node] = min(llv[i], llv[node]);}
	
	if (llv[node] == id[node]) {
		while (s.top() != node) {
			scc[s.top()] = node;
			sccreach[node][s.top()] = 1;
			for (auto k : adj[s.top()]) sccadj[node].push_back(k);
			onstack[s.top()] = 0;
			s.pop();
		}
		onstack[s.top()] = 0;
		for (auto k : adj[s.top()]) sccadj[node].push_back(k);
		sccreach[node][s.top()] = 1;
		s.pop();
	}
	
	return;
}

void sccdfs (int node) {
	if (visited[node]) return;
	visited[node] = 1;
	
	for (auto i : sccadj[node]) {
		sccdfs(scc[i]);
		sccreach[node] |= sccreach[scc[i]];
	}
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
  	cin >> a >> b;
  	adj[a].push_back(b);
  }
  
  for (int i = 1; i <= n; i++) dfs(i);
  for (int i = 1; i <= n; i++) visited[i] = 0;
  for (int i = 1; i <= n; i++) sccdfs(scc[i]);
  
  for (int i = 0; i < q; i++) { cin >> a >> b;
  	sccreach[scc[a]][b] ? cout << "YES\n" : cout << "NO\n";
  }

  return 0;
}


