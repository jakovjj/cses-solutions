#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(ll i = 1; i <= (n); i++)
#define FOR(i, a, b) for (ll i = a; i <= (b); i++)
const ll mod = 1e9+7; const ll N = 2e5;
ll n, x, res[200003], d[200003], pot[200003];
vector<int> divs[200003];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  pot[0] = 1; REP(i, N) pot[i] = (pot[i-1]*2)%mod;
  for (int i = 0; i <= N; i++) pot[i] = (pot[i]-1+mod)%mod;

  REP(i, N) for (int j = i; j <= N; j+=i) divs[j].push_back(i);
	  
  REP(i, n) {
  	cin >> x;
  	for (auto k : divs[x]) d[k]++;	
  }
  
  for (int i = n; i >= 1; i--) {
	res[i] = pot[d[i]];
	for (int j = 2*i; j <= n; j+=i) res[i]=(res[i]-res[j]+mod)%mod;
  }
  
  REP(i, n) cout << res[i] << " ";

  return 0;
}


