#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

ll n, res, x[1003], y[1003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  res = 0;
  
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  for (int i = 1; i <= n-1; i++) res += x[i]*y[i+1]-x[i+1]*y[i];
  res += x[n]*y[1]-x[1]*y[n];
  
  cout << abs(res);

  return 0;
}


