#include <bits/stdc++.h>
using namespace std;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define MEMSET_MAX 0x7f
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int inf = 2147483647; const int mod = 1e9+7;

ll n, k, a[1000003];
bool s[1000003];
vector<ll> t;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for (int i = n; i >= 1; i--) {
  	if (k >= i-1) {
  		t.push_back(i);	
  		s[i] = 1;
  		k-=i-1;
	}
	
  }
  
  for (auto i : t) cout << i << " ";
  for (int i = 1; i <= n; i++) {
  	if (s[i] == 0) cout << i << " ";
  }
  

  return 0;
}

