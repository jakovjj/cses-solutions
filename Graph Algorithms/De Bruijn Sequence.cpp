#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;

int n, x;
vector<int> adj[1<<15];
string s;

void dfs(int node) {
	node%2 ? s+='1' : s+='0';
	
	while(!adj[node].empty()) {
		x = adj[node].back();
		adj[node].pop_back();
		
		dfs(x);
	}
	
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  n--;
  for (int i = 0; i < (1<<n); i++) {
  	x = i;
	x <<= 1;
  	if (x >= (1<<n)) x-= (1<<n);
  	if (n) adj[i].push_back(x);
  	adj[i].push_back(x+1);
  }
  
  s = "";
  for (int i = 1; i < n; i++) s+='0';
  
  dfs(0);
  cout << s;

  return 0;
}


