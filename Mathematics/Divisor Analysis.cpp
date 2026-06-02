#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

ll n, x, k, numres, numsum, numpro, cnt;

ll exp (ll a, ll b) {
	ll r = 1;
	while (b) {
		if (b%2) r = (r*a)%mod;
		b/=2;
		a = (a*a)%mod;
	}
	return r;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  cnt = 1; numres = 1; numsum = 1; numpro = 1;
  
  for (int i = 1; i <= n; i++) {
  	cin >> x >> k;
  	numres = numres*(k+1)%mod;
  	numsum = numsum * (((exp(x, k+1)-1) * exp(x-1, mod-2))%mod) % mod;
  	numpro = exp(numpro, (k+1)) * exp(exp(x, k*(k+1)/2), cnt) % mod;
  	cnt = cnt*(k+1)%(mod-1);
  }
  
  cout << numres << " " << numsum << " " << numpro;

  return 0;
}


