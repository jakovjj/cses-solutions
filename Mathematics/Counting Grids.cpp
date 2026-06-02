#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll n;
__int128 res;

ll exp(ll a, ll b) {
	ll r = 1;
	while (b) {
		if (b%2) r = (r*a)%mod;
		b/=2;
		a=(a*a)%mod;
	}
	
	return r;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  res = exp(2, n*n)+exp(2, (n*n)/2+(n*n)%2)+2*exp(2, (n*n)/4+((n*n)%4!=0));
  res = (res * exp(4, mod-2))%mod;
  
  cout << (ll)res;

  return 0;
}


