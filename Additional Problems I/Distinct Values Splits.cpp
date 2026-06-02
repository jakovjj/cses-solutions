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

ll n, a[200003], dp[200003], pref[200003], mx;
map<ll, ll> l;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  
  REP(i, n) {
  	cin >> a[i];
  	
  	mx = max(mx, l[a[i]]);
  	dp[i] = (pref[i-1]-pref[max(0ll, mx-1)]+mod)%mod;
  	if (!mx) dp[i]++;
  	dp[i] %= mod;
  	
  	pref[i] = (dp[i]+pref[i-1])%mod;
  	l[a[i]] = i;
  }
  
  cout << dp[n];
  return 0;
}


