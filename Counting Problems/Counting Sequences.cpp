#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll n, k, f[3000003], ans;

ll exp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b%2) res = (res*a)%mod;
		b/=2;
		a = (a*a)%mod;
	}
	return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  f[0] = 1; for (ll i = 1; i <= 3000000; i++) f[i] = (f[i-1]*i)%mod;
  
  ans = exp(k, n);
  for (ll i = 1; i <= k; i++) {  	
  	if (i%2) ans -= exp(k-i, n) * (f[k] * exp(f[i]*f[k-i]%mod, mod-2)%mod ) % mod;
  	else ans += exp(k-i, n) * (f[k] * exp(f[i]*f[k-i]%mod, mod-2)%mod ) % mod;
	if (ans < 0) ans += mod;
	ans %= mod;
  }
  
  cout << ans;

  return 0;
}


