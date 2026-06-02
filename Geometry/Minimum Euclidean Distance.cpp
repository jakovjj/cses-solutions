#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
const ll inf = 9*1e18;
 
ll res, xv, yv;
int p, n, x[200003], y[200003];
set<pair<ll, ll>> s;
vector<pair<int, int>> sweep;
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n; res = inf;
  REP(i, n) {cin >> x[i] >> y[i]; sweep.push_back({x[i], i});}
  sort(sweep.begin(), sweep.end()); p = 0;
  s.insert({inf, inf}); s.insert({-inf, -inf});
  
  for (int i = 0; i < n; i++) {
  	xv = x[sweep[i].second]; yv = y[sweep[i].second];
  	ll d = ceil(sqrt(res));
  	while (p < i && sweep[p].first <= sweep[i].first-d) {s.erase({y[sweep[p].second], x[sweep[p].second]}); p++;}
	auto lo = s.lower_bound({yv-d, xv});
	auto hi = s.upper_bound({yv+d, xv});
	for (auto it = lo; it != hi && abs((*it).first) != inf; it++)
		res = min(res, abs(xv-(*it).second)*abs(xv-(*it).second)+abs(yv-(*it).first)*abs(yv-(*it).first));
	s.insert({yv, xv});
  }
  
  cout << res;
  return 0;
}
