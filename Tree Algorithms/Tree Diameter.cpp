#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, a, b, r;

vector<int> graph[200003];
pair<int, int> dist[200003];

void treesearch(int u, int p) {
	
	//cout << "scanning " << u << endl;
 	
	if (graph[u].size() == 1 && u != 1) {return;}
	for (auto i : graph[u]) {
		if (i==p) {continue;}
		
		treesearch(i, u);
		
		if (dist[i].first+1 > dist[u].first) {dist[u].second = dist[u].first; dist[u].first = dist[i].first+1;}
		else if (dist[i].first+1 > dist[u].second) {dist[u].second = dist[i].first+1;}
	}
	
	r = max(r, dist[u].first+dist[u].second);
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  
  for (int i = 0; i < n-1; i++) {
  	cin >> a >> b;
  	graph[a].push_back(b);
  	graph[b].push_back(a);
  }
  
  treesearch(1, 0);
  
  cout << r;
  
  return 0;
}

//JJ

