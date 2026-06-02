#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)

ll n, m, s[1000003], f[1000003], k;
vector<ll> p;
vector<pll> seg;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  REP(i, n) cin >> s[i];
  REP(i, n) cin >> f[i];
  p.push_back(0); seg.push_back({m, 0LL});
  
  REP(i, n) {
  	ll it = lower_bound(p.begin(), p.end(), s[i])-p.begin()-1;
  	k = s[i]*seg[it].first+seg[it].second;
  	if (seg.back().first == f[i]) continue;
  	while (seg.size()-1) {
  		pll a = seg[seg.size()-1]; pll b = seg[seg.size()-2];
		if ((k-a.second)*(b.first-f[i]) < (k-b.second)*(a.first-f[i])) {p.pop_back(); seg.pop_back();}
		else break;
	}
	
  	p.push_back((seg.back().second-k)/(f[i]-seg.back().first)); seg.push_back({f[i], k});
  }
  
  cout << k << "\n";
  return 0;
}


