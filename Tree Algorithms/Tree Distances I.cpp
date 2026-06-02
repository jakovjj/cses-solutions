#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, a, b;

vector<int> graph[200003];
pair<pii, pii> dist[200003];
int r[200003];

void treesearch(int u, int p) {
	
	//cout << "scanning " << u << endl;
	if (graph[u].size() == 1 && u != 1) {return;}
	for (auto i : graph[u]) {
		if (i==p) {continue;}
		
		treesearch(i, u);
		
		if (dist[i].first.first+1 >= dist[u].first.first) {
			
			//value
			dist[u].second.first = dist[u].first.first;dist[u].first.first = dist[i].first.first+1;
			
			//child
			dist[u].second.second = dist[u].first.second; dist[u].first.second = i;
			
			}
		else if (dist[i].first.first+1 >= dist[u].second.first) {
			dist[u].second.first = dist[i].first.first+1;
			dist[u].second.second = i;
			}
	}
	
	return;
}

void getresults(int u, int p) {
	
	for (auto i : graph[u]) {
		if (i == p) {continue;}
		
		if (dist[u].first.first+1 >= dist[i].first.first && dist[u].first.second != i) {
			
			//value
			dist[i].second.first = dist[i].first.first; dist[i].first.first = dist[u].first.first+1;
			
			//parent
			dist[i].second.second = dist[i].first.second; dist[i].first.second = u;
			
			}
		else if (dist[u].first.first+1 >= dist[i].second.first && dist[u].first.second != i) {
			
			dist[i].second.first = dist[u].first.first+1;
			dist[i].second.second = u;
		}
		
		else if (dist[u].second.first+1 >= dist[i].first.first) {
			
			//value
			dist[i].second.first = dist[i].first.first; dist[i].first.first = dist[u].second.first+1;
			
			//parent
			dist[i].second.second = dist[i].first.second; dist[i].first.second = u;
			
			}
		else if (dist[u].second.first+1 >= dist[i].second.first) {
			
			dist[i].second.first = dist[u].second.first+1;
			dist[i].second.second = u;
		}
		
		
		getresults(i, u);
	}
	
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
  
  getresults(1, 0);
  
  //for (int i = 1; i < n+1; i++) {cout << i << " --- " << dist[i].first.first << " (" << dist[i].first.second << ") " << ", " << dist[i].second.first << " (" << dist[i].second.second << ")" << endl;}
  
  for (int i = 1; i < n+1; i++) {
  	cout << dist[i].first.first << " ";
  }
  
  return 0;
}

//JJ

