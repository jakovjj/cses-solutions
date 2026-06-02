#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll n, k, p, ans[103], cnt;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  testcases {
  	cin >> n >> k;
  	
  	if (k*k < n) {cout << "IMPOSSIBLE\n"; continue;}
  	
  	p = n; cnt = 0;
  	while (p > 0) {
  		for (int i = max(1LL, p-k+1); i <= p; i++) ans[++cnt] = i;
		p -= k;
	}
  	
  	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  	cout << "\n";
  }

  return 0;
}


