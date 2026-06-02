#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll n, x, res;
priority_queue<ll> q;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n;
  for (int i = 1; i <= n; i++) {
  	cin >> x;
  	q.push(x);
  	res += q.top()-x;
  	q.pop();
  	q.push(x);
  }
  
  cout << res;

  return 0;
}


