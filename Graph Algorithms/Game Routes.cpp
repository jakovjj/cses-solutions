#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, m;
ll a, b;
ll c, r;

ll top[100003];
int visited[100003];

vector<int> ans; 

ll dp[100003];

ll locator[100003];

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
  	
  	
  	r = 0;
  	for (auto s : backgraph[top[i]]) {r += dp[locator[s]];}
  	r = r%1000000007;
  	dp[i] = r;
  }
  
  //for (int i = 1; i < n+1; i++) {cout << dp[i] << " ";} cout << endl;
  //for (int i = 1; i < n+1; i++) {cout << locator[i] << " ";}
  
  cout << dp[locator[n]];
  
  return 0;
}

//JJ

