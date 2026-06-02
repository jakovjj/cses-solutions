#include <bits/stdc++.h>
using namespace std;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
const ll inf = 1e18;

ll n, m, k, a, b, w;
priority_queue<ll> d[200003];
priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<pll> adj[200003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> k;

  pq.push({0, 1}); d[1].push(0);
  for (int i = 1; i <= m; i++) {cin >> a >> b >> w; adj[a].push_back({b, w});}
  
  while(!pq.empty()) {  	
	pll x = pq.top();
	
	if (x.first > d[x.second].top()) {pq.pop(); continue;}
	for (auto y : adj[x.second]) {
		if (d[y.first].size() < k) {d[y.first].push(x.first+y.second); pq.push({x.first+y.second, y.first});}
		else if (x.first+y.second < d[y.first].top()) {d[y.first].pop(); d[y.first].push(x.first+y.second); pq.push({x.first+y.second, y.first});}
	}
	
  	pq.pop();
  }
	
  stack<ll> res;
  while (!d[n].empty()) {res.push(d[n].top()); d[n].pop();}
  while (!res.empty()) {cout << res.top() << " "; res.pop();}

  return 0;
}


