#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll n, a, b;
vector<ll> graph[200003];
ll sum[200003];

pll v[200003]; //first -> onesided tempsum, second -> number of values included in the tempsum

void scantree(int u, int p) {
	
	if (graph[u].size() == 1 && u != 1) {return;}
	
	for (auto i : graph[u]) {
		if (i == p) continue;
		
		scantree(i, u);
		
		v[u].first += (v[i].first+v[i].second+1);
		v[u].second += (v[i].second+1);	
		
		}
}

void backtracktree(int u, int p) {
	
	for (auto i : graph[u]) {
		if (i == p) continue;
		
		sum[i] = sum[u]+(n-1-v[i].second)-1-v[i].second;
		backtracktree(i, u);
	}
	
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  for (int i = 0; i < n-1; i++) {
  	cin >> a >> b;
  	graph[a].push_back(b);
  	graph[b].push_back(a);}
  	
  scantree(1, 0);
  sum[1] = v[1].first;
  
  backtracktree(1, 0);
  
  //for (int i = 1; i < n+1; i++) cout << v[i].first << " "; cout << endl;
  //for (int i = 1; i < n+1; i++) cout << v[i].second << " "; cout << endl;
  
  for (int i = 1; i < n+1; i++) cout << sum[i] << " "; 
  
  return 0;
}

//JJ

