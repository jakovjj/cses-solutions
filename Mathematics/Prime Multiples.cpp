#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

__int128 res, temp;
ll n, k, a[23];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  
  for (int i = 0; i < k; i++) cin >> a[i];
  
  for (int i = 1; i < (1<<k); i++) {
  	
  	temp = 1;
  	for (int j = 0; j < k; j++) {
  		if ((i&(1<<j)) == 0) continue;
		temp *= a[j];
		if (temp > 1e18) break;
	  }
	  
	if (temp > 1e18) continue;

	(__builtin_popcount(i)%2) ? res+=n/temp : res-=n/temp;
  }
  
  cout << (ll)res;

  return 0;
}


