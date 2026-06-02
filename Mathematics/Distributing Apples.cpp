#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const int inf = 2147483647;

ll n, k, f[2000003], res;

ll exp (ll a, ll b) {
	ll r = 1;
	
	while (b) {
		if (b%2) r=(r*a)%mod;
		b/=2;
		a=(a*a)%mod;
	}
	
	return r;
} 
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  
  f[1] = 1; for (ll i = 2; i <= 2000000; i++) f[i] = f[i-1]*i%mod;
  
  res = f[n+k-1] * (exp((f[k]*f[n-1])%mod, mod-2)%mod) % mod;
  
  cout << max(res, 1LL);

  return 0;
}


