#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
 
ll n, mink, maxk, a, b, sub[200003], cnt[200003], depcnt[200003], tot, sum, pmax, ctrmax;
vector<ll> adj[200003];
bool visited[200003];
ll res;
 
int subdfs(int node, int parent) {
	sub[node] = 1;
	for (auto i : adj[node]) {if (visited[i] || i == parent) continue; sub[node] += subdfs(i, node);}
	return sub[node];
}
 
int find_centroid (int node) {
	for (auto i : adj[node]) {
		if (visited[i]) continue;
		if (sub[i]*2 > sub[node]) {
			swap(sub[i], sub[node]);
			sub[node] = sub[i]-sub[node];
			return find_centroid(i);
		}
	}	
	return node;
}
 
void dfs(int node, int parent, ll depth) {		
	depcnt[depth]++;
	pmax = max(depth, pmax);
	for (auto i : adj[node]) if (i != parent && visited[i] == 0 && depth+1 <= maxk) dfs(i, node, depth+1);
}
 
void solve(int node) {
	int centroid = find_centroid(node);
	
	visited[centroid] = 1;
	sum = (mink == 1); ctrmax = 0;
	
	for (auto i : adj[centroid]) {
		if (visited[i]) continue;
		
		pmax = 0; dfs(i, centroid, 1); cnt[0] = 1;
		tot = sum; 
		
		for (int k = 1; k <= pmax; k++) {
			res += tot * depcnt[k];
			if (maxk-k >= 0) tot -= cnt[maxk-k];
			if (mink-k-1 >= 0) tot += cnt[mink-k-1];
		}
		
		for (ll k = 1; k <= pmax; k++) {cnt[k] += depcnt[k]; if (k >= mink-1 && k <= maxk-1) sum += depcnt[k];}
		fill(depcnt, depcnt+pmax+1, 0); ctrmax = max(ctrmax, pmax);
	}
	
	fill(cnt+1, cnt+ctrmax+1, 0);
	for (auto i : adj[centroid]) if (!visited[i]) solve(i);
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n >> mink >> maxk;
  
  for (int i = 1; i <= n-1; i++) {cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);}
  subdfs(1, 0); solve(1); 
  
  cout << res;
 
  return 0;
}	
