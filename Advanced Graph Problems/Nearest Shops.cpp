#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)

int n, m, k, distf[100003], r[100003], dists[100003];
bool anim[100003];
vector<int> adj[100003];
queue<pair<pair<int, int>, int>> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> k;
  REP(i, k) {
  	int x; cin >> x; anim[x] = 1;
  	q.push({{x, 0}, x});
  }
  
  REP(i, m) {
  	int u, v;
  	cin >> u >> v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }
  
  while (!q.empty()) {
  	pair<pair<int, int>, int> x = q.front(); q.pop();
  	int d = x.first.second; int node = x.first.first; int s = x.second;
  	
  	if (dists[node] || (r[node] == s)) continue;
  	if (!r[node]) {r[node] = s; distf[node] = d;}
	else dists[node] = d;
  	
  	for (auto i : adj[node]) {
  		q.push({{i, d+1}, s});	
	}
  }
  
  REP(i, n) {
  	if (distf[i]) cout << distf[i] << " ";
  	else if (dists[i]) cout << dists[i] << " ";
  	else cout << "-1 ";
  }

  return 0;
}


