#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const ll inf = 1e18;

ll n, m, res;

ll gcd(ll a, ll b) {
	if (b) return(gcd(b, a%b));
	return(a);
} 

ll exp(ll a, ll b){
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
	
  cin >> n >> m;
  
  for (int i = 1; i <= n; i++) {
  	res = (res+exp(m, gcd(i, n)))%mod;
  }
  
  res = (res*exp(n, mod-2))%mod;
  cout << res << "\n";

  return 0;
}


