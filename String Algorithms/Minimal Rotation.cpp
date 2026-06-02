#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;
const ll p = 31;

ll n, hashv[1000003], pot[1000003], h[3], ansidx, idx, lo, hi, mid, res;
string s;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s;
  ansidx = 0; n = s.size(); pot[0] = 1; hashv[0] = s[0];
  for (int i = 1; i < n; i++) {hashv[i] = (hashv[i-1]*p+s[i])%mod; pot[i] = pot[i-1]*p%mod;}
  
  for (int i = 1; i < n; i++) {
  	lo = 0; hi = n;
  	
  	res = n-1;
  	while (lo <= hi) {
  		mid = (lo+hi)/2;
		
		for (int k = 1; k <= 2; k++) {
			(k == 1) ? idx = i : idx = ansidx;
			
			h[k] = hashv[min(n-1, idx+mid)];
			if (idx+mid >= n) {
				h[k] = (h[k]-hashv[idx-1]*pot[n-idx])%mod;
				
				h[k] = (h[k]*pot[mid-(n-idx)+1])%mod;
				h[k] += hashv[(idx+mid)%n];
			}
			else h[k] = (h[k]-hashv[idx-1]*pot[mid+1])%mod;
			
			if (h[k] < 0) h[k] += mod;
		}
		
		if (h[1]%mod == h[2]%mod) lo = mid+1;
		else {hi = mid-1; res = min(res, mid);}
	}
	
	if (s[(i+res)%n] < s[(ansidx+res)%n]) ansidx = i;
  }
  
  for (int i = ansidx; i < n; i++) cout << s[i];
  for (int i = 0; i < ansidx; i++) cout << s[i];

  return 0;
}


