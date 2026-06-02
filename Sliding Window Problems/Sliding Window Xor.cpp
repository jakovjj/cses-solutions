#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;
mt19937 rng(time(0));
 
ll n, k, x, a, b, c, arr[10000003], sum, res;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n >> k;
  cin >> x >> a >> b >> c;
  
  arr[1] = x;
  FOR(i, 2, n) arr[i] = (a*arr[i-1]+b)%c;
  sum = 0;
  
  REP(i, k) sum ^= arr[i];
  res ^= sum;
  
  FOR(i, k+1, n) {
  	sum ^= arr[i]^arr[i-k];
  	res ^= sum;
  }
 
  cout << res;
  return 0;
}

