#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;
mt19937 rng(time(0));

ll n, g, a[200003], s, adj[200003], sieve[200003], pot[200003], res, x, w;
vector<ll> p;
bool vis[200003];

void dfs(ll x) {
	if (vis[x]) return;
	vis[x] = 1; s++; dfs(adj[x]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  
  FOR(i, 2, n) {
  	if (!sieve[i]) {
  		p.push_back(i);
		for (int j = i; j <= n; j += i) sieve[j] = i;	
	}
  }
  
  REP(i, n) {cin >> a[i]; adj[i] = a[i]; pot[i] = 1;}
  REP(i, n) {
  	if (vis[i]) continue;
  	s = 0; dfs(i);
  	x = sieve[s]; w = 1;
  	while (s-1) {
		if (x != sieve[s]) {
			pot[x] = max(pot[x], w);
			x = sieve[s]; w = 1;
		}
		w *= x;
		s /= x;
	}
	pot[x] = max(pot[x], w);
  	
  }
  
  res = 1;
  REP(i, n) res = (res*pot[i])%mod;
  cout << res;
  return 0;
}


