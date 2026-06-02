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

ll n, dp[200003], a[200003], res;
map<ll, ll> l;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  REP(i, n) {
  	cin >> a[i];
  	dp[i] = dp[i-1]+i-l[a[i]];
  	l[a[i]] = i;
  	res += dp[i];
  }

  cout << res;

  return 0;
}


