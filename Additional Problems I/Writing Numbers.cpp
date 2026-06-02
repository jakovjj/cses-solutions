#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
const ll inf = 1e19;

ll n, pot[21], lo, hi, mid, res, cnt, num, rem, dig;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  
  lo = 1; hi = inf;
  pot[1] = 1; for (int i = 2; i <= 19; i++) pot[i] = pot[i-1]*10;
  while (lo <= hi) {  	
  	mid = (lo+hi)/2;
  	
  	num = mid; cnt = 0; ll i = 1; rem = 0;
  	while (num) {
  		dig = num%10;
  		num /= 10;
  		
  		cnt += (num+(dig > 0))*pot[i];
  		if (dig == 1) cnt += rem+1-(dig > 0)*pot[i];
  		
  		rem += dig*pot[i];
  		i++;
	}
  	
  	if (cnt > n) {hi = mid-1;}
  	else {lo = mid+1; res = max(res, mid);}
  }
  
  cout << res << "\n";

  return 0;
}


