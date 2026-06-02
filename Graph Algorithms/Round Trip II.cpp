#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
int n, m, a, b;
bool fc;
int chosen;
bool d;
bool visited[100003];
bool _stack[100003];
vector<int> graph[100003];
vector<int> result;
 
vector<int> route;
 
void dfs(int node) {
	if(d==1) {return;}
	if(visited[node] == 1) {return;}
	
	visited[node] = 1; 
	_stack[node] = 1;
	route.push_back(node);
	
	for (auto u : graph[node]) {if(_stack[u] == 1) {d = 1; if (chosen == 0) {chosen = u;}

	break;}
	else {dfs(u);}}
	
	if (d==1) {return;}
	
	route.pop_back();
	_stack[node] = 0;
	return;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  d = 0;
  chosen = 0;
  
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
  	cin >> a >> b;
  	graph[a].push_back(b);}
  	
  for (int i = 1; i < n+1; i++) {
  	if (!route.empty()) {break;}
  	if (visited[i] == 0) {dfs(i);}}
 
  fc = 0;
  if (route.empty()) {cout << "IMPOSSIBLE";}
  else {
	  for (auto i : route) {
	  	if (i == chosen) {fc=1;}
	  	if (fc == 1) {result.push_back(i);}
	  }
  	  cout << result.size()+1 << endl;
  	  for (auto i : result) {cout << i << " ";} cout << chosen;
  }
  
  
  return 0;
}

//JJ
