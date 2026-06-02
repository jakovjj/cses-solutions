#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
const int inf = 1e9;

int n, flow[203][203], maxflow[203][203], pt[203];
char mat[103][103];
vector<int> adj[203];
vector<pair<int, int>> ans;

bool bfs() {
	queue<pair<int, int>> q;
	q.push({0, 0}); bool reached = 0;
	
	while (!q.empty()) {
		int x = q.front().first; 
		if (pt[x] != -1) {q.pop(); continue;}
		pt[x] = q.front().second; q.pop();
		if (x == 201) {reached = 1; break;}
		for (auto i : adj[x]) {if (pt[i] == -1 && flow[x][i] < maxflow[x][i]) q.push({i, x});}		
	}
	
	return reached;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  REP(i, n) REP(j, n) {
  	cin >> mat[i][j];
  	if (mat[i][j] == 'o') {
  		adj[i].push_back(n+j);
		adj[n+j].push_back(i);
		maxflow[i][n+j] = inf;	
	}
  }
  
  REP(i, n) {
	maxflow[0][i] = 1;
	maxflow[n+i][201] = 1;
	adj[0].push_back(i); adj[i].push_back(0);
	adj[201].push_back(n+i); adj[n+i].push_back(201);
  }
  
  memset(pt, -1, sizeof(pt));
  while (bfs()) {
  	int x = 201;
  	while (x > 0) {
  		flow[pt[x]][x]++;
  		flow[x][pt[x]]--;
  		x = pt[x];
	}
	memset(pt, -1, sizeof(pt));
  }
  
  bfs();
  REP(i, n) if (pt[i] == -1) ans.push_back({1, i});
  for (int i = n+1; i <= 2*n; i++) if (pt[i] != -1) ans.push_back({2, i-n});
  
  cout << ans.size() << "\n";
  for (auto i : ans) cout << i.first << " " << i.second << "\n";

  return 0;
}

