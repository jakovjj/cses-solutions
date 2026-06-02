#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#pragma GCC optimize ("Ofast,unroll-loops")
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;
mt19937 rng(time(0));
 
ll n, k, x, a, b, c, arr[10000003], res;
deque<pair<ll, ll>> q;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n >> k;
  cin >> x >> a >> b >> c;
  
  arr[1] = x;
  FOR(i, 2, n) arr[i] = (a*arr[i-1]+b)%c;
  
  REP(i, k) {
  	while (!q.empty() && q.back().first > arr[i]) q.pop_back();  	
  	q.push_back({arr[i], i});
  }
  res ^= q.front().first;
  
  FOR(i, k+1, n) {
  	while (!q.empty() && q.back().first > arr[i]) q.pop_back();
  	while (!q.empty() && q.front().second <= i-k) q.pop_front();
  	q.push_back({arr[i], i});
  	res ^= q.front().first;
  }
 
  cout << res;
  return 0;
}
