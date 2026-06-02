#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, a, b;

int dp_include[200003];
int dp_exclude[200003];

vector<int> graph[200003];

void subtree_matching(int u, int p) {
	
	if (graph[u].size() <= 1 && u != 1) {dp_include[u] = 0; dp_exclude[u] = 0; return;}
	
	int temp = 0;
	for (auto v : graph[u]) {
		if (v == p) {continue;}
		if (dp_exclude[v] == -1) {subtree_matching(v, u);}
		
		temp+=max(dp_exclude[v], dp_include[v]);
	} dp_exclude[u] = temp;
	
	
	for (auto v : graph[u]) {
		if (v == p) {continue;}
		
		int r;
		r = dp_exclude[v]+1+dp_exclude[u]-max(dp_exclude[v], dp_include[v]);
		dp_include[u] = max(dp_include[u], r);
	}
	
	return;
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  
  memset(dp_include, -1, sizeof(dp_include));
  memset(dp_exclude, -1, sizeof(dp_exclude));
  
  for (int i = 0; i < n-1; i++) {cin >> a >> b;
  	graph[a].push_back(b);
  	graph[b].push_back(a);
  }
  
  subtree_matching(1, 0);
  
  //for (int i = 1; i < n+1; i++) {cout << i << " > " << dp_include[i] << " " << dp_exclude[i] << endl;}
  cout << max(dp_include[1], dp_exclude[1]);
  
  return 0;
}

//JJ

