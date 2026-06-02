#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;

int n, m, a, b, q, res[200003], un[200003];
vector<pii> roads, queries[200003];
vector<int> unions[200003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {unions[i].push_back(i); un[i] = i;}
  for (int i = 1; i <= m; i++) {
  	cin >> a >> b;
  	roads.push_back({a, b});
  }
    
  for (int i = 1; i <= q; i++) {
  	cin >> a >> b;
  	res[i] = -1;
  	if (a == b) {res[i] = 0; continue;}
  	queries[a].push_back({b, i});
  	queries[b].push_back({a, i});
  }
  
  int c = 1;
  for (auto i : roads) {
  	a = un[i.first]; b = un[i.second];
  	if (unions[a].size() < unions[b].size()) swap(a, b);
  	if (a == b) {c++; continue;}
  	
  	for (auto k : unions[b]) {un[k] = a; unions[a].push_back(k);} unions[b].clear();
	for (auto l : queries[b]) {
		if (res[l.second] != -1) continue;
		if (un[l.first] == a) res[l.second] = c; else queries[a].push_back(l);
	}
	queries[b].clear();
	
	c++;
  }
  
  for (int i = 1; i <= q; i++) cout << res[i] << "\n";

  return 0;
}


