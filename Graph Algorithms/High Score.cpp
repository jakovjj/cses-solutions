#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int a, b, c;

bool im;

vector<pair<int, int>> graph[2503];
vector<pair<int, int>> reverse_graph[2503];
ll dist[2503];

ll dist_check[2503];
bool marked[2503];
int visited[2503];

ll inf = -9999999999999999;

void dfs(int node) {
	if (im == 1) {return;}
	if (marked[node] == 1) {im = 1; return;}
	if (visited[node] == 1) {return;}
	visited[node] = 1;
	
	
	for (auto i : reverse_graph[node]) {
		dfs(i.first);	
	} 
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  
  im = 0;
  
  for (int i = 0; i < m; i++) {
  	cin >> a >> b >> c;
  	graph[a].push_back(make_pair(b, c));
  	reverse_graph[b].push_back(make_pair(a, c));
  }
  
  for (int i = 1; i < n+1; i++) {dist[i]=inf;}
  dist[1] = 0;
  
  for (int l = 0; l < m; l++) {
  	for (int i = 1; i < n+1; i++) {
  	
	  for (auto s : graph[i]) { 	
	  	if (dist[i] == inf) {continue;}
	  	dist[s.first] = max(dist[s.first], dist[i]+s.second);	
	}
  }}
  
  for (int i = 0; i < n+1; i++) {dist_check[i] = dist[i];}
  
  for (int i = 1; i < n+1; i++) {
  	
	  for (auto s : graph[i]) {
	  	
	  	if (dist_check[i] == inf) {continue;}
	  	dist_check[s.first] = max(dist_check[s.first], dist_check[i]+s.second);	
	}}
	
  for (int i = 0; i < n+1; i++) {
  	if (dist_check[i] != dist[i]) {marked[i] = 1;}}
  	
  dfs(n);
  
  //for (int i = 1; i < n+1; i++) {cout << dist[i] << " ";} cout << endl;
  //for (int i = 1; i < n+1; i++) {cout << dist_check[i] << " ";} 
  
  if (im == 1) {cout << "-1"; return 0;}
  cout << dist[n];
  
  return 0;
}

//JJ

