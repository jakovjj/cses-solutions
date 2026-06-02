#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for(int i = a; i <= (b); i++)
const ll mod = 1e9+7; const ll inf = 1e18; const ll b = 13337;
const ll mod2 = 998244353;

string s;
ll h[100003], pot[100003], h2[100003], pot2[100003], res, n, idx;
map<pair<ll, ll>, ll> vis;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s; n = s.size();
  pot[0] = 1; REP(i, 100000) pot[i] = (pot[i-1]*b)%mod;
  pot2[0] = 1; REP(i, 100000) pot2[i] = (pot2[i-1]*b)%mod2;
  REP(i, n) h[i] = (h[i-1]*b+s[i-1])%mod; 
  REP(i, n) h2[i] = (h2[i-1]*b+s[i-1])%mod2;
  
  ll lo = 1; ll hi = n; ll mid;
  while (lo <= hi) {
  	mid = (lo+hi)/2;
  	vis.clear();
  	
  	bool w = 0;
  	for (int i = 1; i <= n-mid+1; i++) {
  		ll hv = (h[i+mid-1]-(h[i-1]*pot[mid])%mod+mod)%mod;
  		ll hv2 = (h2[i+mid-1]-(h2[i-1]*pot2[mid])%mod2+mod2)%mod2;
  		
		if (!vis[{hv, hv2}]) vis[{hv, hv2}] = i;
		else {w = 1; res = mid; idx = vis[{hv, hv2}]; break;}
	}

	if (w) {lo = mid+1;}
	else hi = mid-1;
  }
  
  if (!res) {cout << "-1"; return 0;}
  FOR(i, idx, idx+res-1) cout << s[i-1];
  return 0;
}
