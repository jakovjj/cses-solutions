#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int a, b;
int c;

int top[100003];
int visited[100003];

vector<int> ans; 

int dp[100003];

int locator[100003];

vector<int> graph[100003];
vector<int> backgraph[100003];

void topsort(int node) {
	visited[node] = 1;
	
	for (auto s : graph[node]) {
		if (visited[s] == 0) {topsort(s);}
	}
	
	locator[node] = c;
	top[c] = node; c--;
	
	return;
}

void backtrack(int node) {
	
	ans.push_back(node);
	if (node == 1) {return;}
	
	int r = 0;
	int rnode = 0;
	
	for (auto  s : backgraph[node]) {
		if (dp[locator[s]] > r) {r = dp[locator[s]]; rnode = s;}
	}
	
	backtrack(rnode);
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  
  for (int i = 0; i < m; i++) {
  	cin >> a >> b;
  	
  	graph[a].push_back(b);
  	backgraph[b].push_back(a);
  }
  
  c = n;
  for (int i = 1; i < n+1; i++) {
  	if (visited[i] == 0) {topsort(i);}
  }
  
  //for (int i = 1; i < n+1; i++) {cout << top[i] << " ";} cout << endl;
  
  dp[locator[1]] = 1;
  
  for (int i = locator[1]+1; i < n+1; i++) {
  	
  	
  	int r = 0;
  	for (auto s : backgraph[top[i]]) {r = max(r, dp[locator[s]]+1);}
  	
  	dp[i] = r;
  }
  
  //for (int i = 1; i < n+1; i++) {cout << dp[i] << " ";} cout << endl;
  //for (int i = 1; i < n+1; i++) {cout << locator[i] << " ";}
  
  if(dp[locator[n]] == 0) {cout << "IMPOSSIBLE"; return 0;}
  
  backtrack(n);
  
  cout << ans.size() << endl;
  for (int i = ans.size()-1; i >= 0; i--) {cout << ans.at(i) << " ";}
  
  return 0;
}

//JJ

