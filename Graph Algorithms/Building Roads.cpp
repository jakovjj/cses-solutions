#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a, b, r;

vector<int> graph[100003];
vector<pair<int, int>> results;
int visited[100003];

void dfs(int ind) {
	if (visited[ind] == 1) {return;}
	visited[ind] = 1; 
	//cout << "Visiting " << ind;
	
	for (int i = 0; i < graph[ind].size(); i++) {
		dfs(graph[ind].at(i)-1);
	}
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  
  r = -1;
  
  for (int i = 0; i < m; i++) {
  	cin >> a >> b;
  	
  	graph[a-1].push_back(b);
  	graph[b-1].push_back(a);
  }

  //debug  
  //cout << "| "; for (int i = 0; i < n; i++) { for (int j = 0; j < graph[i].size(); j++) { cout << graph[i].at(j) << " "; } cout << "| "; } cout << endl;
  
  for (int i = 0; i < n; i++) {if(visited[i] == 0) {
  if (i != 0) {results.push_back(make_pair(1, i+1));}
  dfs(i); r++;
  }}
  
  cout << r << endl;
  
  for (int i = 0; i < results.size(); i++) {
  	cout << results.at(i).first << " " << results.at(i).second << endl;
  }
  
  return 0;
}

//JJ

