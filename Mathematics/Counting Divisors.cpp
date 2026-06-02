#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

int n, x, res;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
  	cin >> x;
  	res = 0;
  	for (int j = 1; j*j <= x; j++) {
  		if (x%j==0) {
  			res++;
  			if (j*j != x) res++;	
		}	
	}
	
	cout << res << "\n";
  	
  }

  return 0;
}


