#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll q, n, k, st, up;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> q;
  for (int i = 1; i <= q; i++) {
  	cin >> n >> k;
  	st = 1;
  	up = 2;
  	
  	bool w = 0;
  	
  	while (n/2 < k) {
  		if (n%2) st += up;
  		k -= n/2;
  		up *= 2;
  		if (n%2 && k == 1) {cout << st-up/2 << "\n"; w = 1;}
  		if (n%2) k--;
  		n/=2;
  		
  		//cout << "now it's " << n << "," << k << " starting at " << st << "\n";
	}
	
	if (!w) cout << st+up*k-up/2 << "\n";
  	
  }

  return 0;
}


