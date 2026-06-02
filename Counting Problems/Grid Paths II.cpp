#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
const ll mod = 1e9+7;

ll n, m, x, y, dp[3003], f[2000003], cnt;
vector<pll> t;

bool cpr (pll a, pll b) {return a.first+a.second < b.first+b.second;}
ll exp(ll a, ll b) {ll r = 1; while (b) {if (b%2) r = (r*a)%mod; b/=2; a = (a*a)%mod;} return r;}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  REP(i, m) {cin >> x >> y; t.push_back({x, y});} t.push_back({n, n});
  sort(t.begin(), t.end(), cpr);
  f[0] = 1; REP(i, 2000001) f[i] = (f[i-1]*i)%mod;
  
  for (auto i : t) {
  	x = i.first-1; y = i.second-1;
  	dp[++cnt] = (f[x+y]*exp((f[x]*f[y])%mod, mod-2))%mod;
  	
  	ll id = 0;
  	for (auto j : t) {
  		id++; if (id >= cnt || j.first > i.first || j.second > i.second) continue;
		x = i.first-j.first; y = i.second-j.second;
		dp[cnt] -= (dp[id]*((f[x+y]*exp((f[x]*f[y])%mod, mod-2))%mod))%mod;
		dp[cnt] = (dp[cnt]+mod*mod)%mod;
	}
  }
  
  cout << dp[m+1];
  return 0;
}

