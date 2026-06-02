#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n, m;
int a, b;
int c;
bool im;
int top[100003];
int check[100003];
bool visited[100003];
 
vector<int> graph[100003];
 
void dfs(int node) {
	if (visited[node] == 1) {return;}
	visited[node] = 1;
	
	int r = 0;
	
	for (int i = 0; i < graph[node].size(); i++) {
		dfs(graph[node].at(i));
	}
	
	top[c] = node;
	check[top[c]] = c;
	c--;
	
	
	return;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  
  c = n;
  
  for (int i = 1; i < m+1; i++) {cin >> a >> b; if (a == b) im = 1; graph[a].push_back(b);}
  for (int i = 1; i < n+1; i++) {if (visited[i] == 0) {dfs(i);}}
  
  for (int i = 1; i < n+1; i++) {
  	for (int j = 0; j < graph[i].size(); j++) {
  		if (check[i] > check[graph[i].at(j)]) {im = 1; break;}
	  }
	if (im == 1) {break;}
  }
  
  if (im == 1) {cout << "IMPOSSIBLE"; return 0;} 
  for (int i = 1; i < n+1; i++) {cout << top[i] << " ";} cout << endl;
  //for (int i = 1; i < n+1; i++) {cout << check[i] << " ";}
  
  return 0;
}
 
//JJ

