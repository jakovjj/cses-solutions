#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define mpr make_pair
#define mtp make_tuple
#define MEMSET_MAX 0x7f
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)

const ll mod = 1e9+7;
string s;
ll res, av, arr[26], f[1000003];

ll exp (ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b%2) {res = res*a; res%=mod;}
		b/=2;
		a = (a*a)%mod;
	}
	
	return res;
}

ll choose (ll up, ll lo) {
	ll modinv = exp ( ((f[lo]*f[up-lo])%mod), mod-2 ) % mod;
	ll res = f[up]*modinv;
	
	return res%mod;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) arr[s[i]-'a']++;
  av = (int)s.size();
  f[0] = 1; f[1] = 1; for (int i = 2; i <= 1000000; i++) f[i] = (f[i-1]*i)%mod;
  
  res = 1;
  for (int i = 0; i <= 26; i++) {
  	if (!arr[i]) continue;
  	
  	res*=choose(av, arr[i]);
  	res%=mod;
  	av-=arr[i];
  }
  
  cout << res%mod;
  
  return 0;
}


