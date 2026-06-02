#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

ll n, lo, hi, mid, res, sum;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  lo = 1; hi = 1e12;
  
  res = 1e12;
  
  while (lo <= hi) {
  	mid = (lo+hi)/2;
  	sum = 0;
  	
  	for (int i = 1; i <= n; i++) sum += min(n, mid/i);
  	
  	if (sum > (n*n)/2) {res = min(res, mid); hi = mid-1;}
  	else lo = mid+1;
  }
  
  cout << res;
	
  return 0;
}


