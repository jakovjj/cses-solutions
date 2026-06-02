#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9+7;
const int inf = 2147483647;

int n, t;
int visited[200005];
int tree[200005];

vector<int> graph[200005];

void dfs(int node, int parent) {
	if (visited[node]) {return;}

	visited[node] = 1;
	if (graph[node].size() != 0) {
		for (auto i : graph[node]) {
		//cout << "from " << node << " looking at " << i << endl;
		dfs(i, node);}	
	}	
	
	//cout << "adding from " << node << " to " << parent << " --> " << 1+tree[node] << endl; 
	tree[parent] += 1+tree[node];
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  for (int i = 2; i < n+1; i++) {cin >> t; graph[t].push_back(i);}
  dfs(1, 0);
  
  for (int i = 1; i < n+1; i++) {cout << tree[i] << " ";}
  
  return 0;
}

//JJ

