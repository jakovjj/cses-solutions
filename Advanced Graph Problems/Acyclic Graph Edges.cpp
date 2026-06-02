#include <bits/stdc++.h>
using namespace std;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define MEMSET_MAX 0x7f
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll inf = 1e16; const int mod = 1e9+7;

ll n, m, a, b;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
  	cin >> a >> b;
  	if (a > b) swap(a, b);
  	cout << a << " " << b << "\n";
  }


  return 0;
}

