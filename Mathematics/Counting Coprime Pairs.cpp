#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[100016], res, sieve[1000016], p[103], cnt, divs[1000016], v;
bool vis[1000016], sq[1000016];
vector<ll> rem, prim;

void pie() {
	for (int i = 1; i < (1<<cnt); i++) {
		v = 1;
		
		for (ll j = 0; j < 22; j++) if (((1LL<<j)&i)) v*= p[j+1]; 
		if (vis[v] || sq[v]) continue;
		
		(__builtin_popcountll(i)%2) ? res-=divs[v] : res+=divs[v];
				
		divs[v]++; vis[v] = 1;
		rem.push_back(v);
	}
	
	for (auto i : rem) vis[i] = 0;
	rem.clear();
	
	return;
}

void factorize(ll x) {	
	cnt = 0;
	while (x != 1) {
		p[++cnt] = sieve[x];
		x = x/sieve[x];
	}

	pie();	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  res = (n*(n-1))/2;
  for (ll i = 1; i <= n; i++) cin >> a[i];
  
  for (ll i = 2; i <= 1000000; i++) if (!sieve[i]) {
  	prim.push_back(i);
  	for (ll j = i; j <= 1000000; j+=i) sieve[j] = i;	
  }
  
  for (auto i : prim) {
  	v = i*i;
  	if (v > 1000000) break;
  	for (int j = v; j <= 1000000; j+=v) sq[j] = 1;
  }
  
  for (ll i = 1; i <= n; i++) factorize(a[i]);
  
  cout << res;

  return 0;
}

