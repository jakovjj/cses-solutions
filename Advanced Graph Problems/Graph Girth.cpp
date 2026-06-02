#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

int n, m, a, b, dist[2503], res;
vector<int> adj[2503];
queue<int> q;

void bfs(int node) {	
	for (auto i : adj[node]) {
		if (dist[i] >= dist[node]) res = min(res, 1+dist[node]+dist[i]);
		if (dist[i] == -1) {dist[i] = dist[node]+1; q.push(i);}
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
  
  res = 1e9;
  
  for (int i = 1; i <= n; i++) {
  	for (int j = 1; j <= n; j++) dist[j] = -1;
  	dist[i] = 0; q.push(i);
  	
  	while (!q.empty()) {bfs(q.front()); q.pop();}
  }
  
  (res == 1e9) ? cout << "-1" : cout << res; 

  return 0;
}


