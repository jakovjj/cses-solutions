#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a, b;
bool imp;
vector<int> graph[100003];
int visited[100003];

void dfs(int slot, int team) {
	visited[slot] = team;
	
	if (team == 1) {team = 2;} else {team = 1;}
	
	
	for (int i = 0; i < graph[slot].size(); i++) {
  		if (visited[graph[slot].at(i)] == 0) {
  			dfs(graph[slot].at(i), team);
		}
		else if (visited[graph[slot].at(i)] != team) {imp = true;}
  	}
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  imp = 0;
  
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
  	cin >> a >> b;
  	graph[a].push_back(b);
  	graph[b].push_back(a);
  }
  
  for (int i = 1; i < n+1; i++) {
  
  if (visited[i] == 0) {
  //cout << "debug " << i;
  dfs(i, 1);
  }}
  
  
  //debug
  //for (int i = 1; i < n+1; i++) {cout << " |< "; for (int j = 0; j < graph[i].size(); j++) {cout << graph[i].at(j) << " ";}} cout << endl;
  
  if (imp == 0) {
	for (int i = 1; i < n+1; i++) {cout << visited[i] << " ";}  	
  }
  else {cout << "IMPOSSIBLE";}

  
  return 0;
}

//JJ

