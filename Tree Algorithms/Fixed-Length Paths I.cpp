#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
 
int n, k, a, b, sub[200003], cnt[200003];
vector<int> adj[200003], deps;
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
 
void dfs(int node, int parent, int depth) {
	deps.push_back(depth);
	for (auto i : adj[node]) if (i != parent && visited[i] == 0) dfs(i, node, depth+1);
	return;
}
 
void solve(int node) {
	int centroid = find_centroid(node);
	vector<int> depsall;
	
	visited[centroid] = 1;
	
	for (auto i : adj[centroid]) {
		if (visited[i]) continue;		
		deps.clear();
		dfs(i, centroid, 1);
		for (auto j : deps) {if (k-j >= 0) res += cnt[k-j]; depsall.push_back(j);}
		for (auto j : deps) cnt[j]++;
	}
	
	for (auto i : depsall) cnt[i]--;
	for (auto i : adj[centroid]) if (!visited[i]) solve(i);
	return;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n >> k; res = 0;
  for (int i = 1; i <= n-1; i++) {cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);}
  subdfs(1, 0); cnt[0] = 1;
  solve(1); cout << res << "\n";
 
  return 0;
}
